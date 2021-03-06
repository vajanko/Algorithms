#ifndef worker_hdr
#define worker_hdr

#include<mpi.h>
#include<fstream>
#include<string>

#define TAG 0

class worker
{
private:
	// sizes of the multiplied matrices
	size_t dim1, dim2, dim3;

	int master_id;
	int worker_id;
	void *req_buff;
	size_t req_buff_size;
	// sizes of matrix the worker is currently working on
	size_t my_dim1, my_dim2, my_dim3;
	matrix a, b, res;
	std::ofstream log_file;

public:
	void allocate_buffers(size_t dim1, size_t dim2, size_t dim3)
	{
		req_buff_size = sizeof(unsigned long)* 3 + sizeof(float)* (dim1 * dim2 + dim2 * dim3);
		req_buff = new char[req_buff_size];
		a = matrix_alloc(dim1, dim2);
		b = matrix_alloc(dim2, dim3);
		res = matrix_alloc(dim1, dim3);
	}
	void init()
	{
		int max_chunk[3];
		MPI_Bcast(max_chunk, 3, MPI_INT, master_id, MPI_COMM_WORLD);
		dim1 = max_chunk[0];
		dim2 = max_chunk[1];
		dim3 = max_chunk[2];

		max_chunk[0] = 1;
		max_chunk[1] = dim1;
		max_chunk[2] = dim3;

		// allocate buffers
		req_buff_size = sizeof(unsigned long)* 3 + sizeof(float)* (max_chunk[0] * max_chunk[1] + max_chunk[1] * max_chunk[2]);
		req_buff = new char[req_buff_size];
		a = matrix_alloc(max_chunk[0], max_chunk[1]);
		b = matrix_alloc(max_chunk[1], max_chunk[2]);
		res = matrix_alloc(max_chunk[0], max_chunk[2]);
	}
	void receive(matrix a, matrix b, size_t &chunk_dim1, size_t &chunk_dim2, size_t &chunk_dim3)
	{
		MPI_Status status;
		MPI_Recv(req_buff, req_buff_size, MPI_PACKED, master_id, TAG, MPI_COMM_WORLD, &status);

		int pos = 0;
		MPI_Unpack(req_buff, req_buff_size, &pos, &chunk_dim1, 1, MPI_UNSIGNED_LONG, MPI_COMM_WORLD);
		MPI_Unpack(req_buff, req_buff_size, &pos, &chunk_dim2, 1, MPI_UNSIGNED_LONG, MPI_COMM_WORLD);
		MPI_Unpack(req_buff, req_buff_size, &pos, &chunk_dim3, 1, MPI_UNSIGNED_LONG, MPI_COMM_WORLD);
		MPI_Unpack(req_buff, req_buff_size, &pos, a, chunk_dim1 * chunk_dim2, MPI_FLOAT, MPI_COMM_WORLD);
		MPI_Unpack(req_buff, req_buff_size, &pos, b, chunk_dim2 * chunk_dim3, MPI_FLOAT, MPI_COMM_WORLD);
	}
	void send(matrix res, size_t rows, size_t cols)
	{
		MPI_Send(res, rows * cols, MPI_FLOAT, master_id, TAG, MPI_COMM_WORLD);
	}
	void process_task(matrix a, matrix b, size_t chunk_dim1, size_t chunk_dim2, size_t chunk_dim3)
	{
		for (size_t i = 0; i < chunk_dim1; ++i)
		{
			for (size_t j = 0; j < chunk_dim3; ++j)
			{
				int sum = 0;
				
				for (size_t k = 0; k < chunk_dim2; ++k)
				{
					sum += (int)a[i * chunk_dim2 + k] * (int)b[k * chunk_dim3 + j];
				}
				res[i * chunk_dim2 + j] = sum;
			}
		}
	}
	void work()
	{
		init();

		while (true)
		{
			receive(a, b, my_dim1, my_dim2, my_dim3);

			if (my_dim1 == 0 && my_dim2 == 0 && my_dim3 == 0)
				break;		// end of calculation

			process_task(a, b, my_dim1, my_dim2, my_dim3);

			send(res, my_dim1, my_dim3);
		}

		finish();
	}
	void finish()
	{
		delete[] (char *)req_buff;
		matrix_free(res);
		matrix_free(a);
		matrix_free(b);
	}

	worker(int worker_id, int master_id) : 
		worker_id(worker_id), master_id(master_id), log_file("tmp.dat") { }
};

#endif