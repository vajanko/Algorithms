/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DUTOK_PROGRAM = 258,
     DUTOK_LABEL = 259,
     DUTOK_CONST = 260,
     DUTOK_TYPE = 261,
     DUTOK_VAR = 262,
     DUTOK_BEGIN = 263,
     DUTOK_END = 264,
     DUTOK_PROCEDURE = 265,
     DUTOK_FUNCTION = 266,
     DUTOK_ARRAY = 267,
     DUTOK_OF = 268,
     DUTOK_GOTO = 269,
     DUTOK_IF = 270,
     DUTOK_THEN = 271,
     DUTOK_ELSE = 272,
     DUTOK_WHILE = 273,
     DUTOK_DO = 274,
     DUTOK_REPEAT = 275,
     DUTOK_UNTIL = 276,
     DUTOK_FOR = 277,
     DUTOK_OR = 278,
     DUTOK_NOT = 279,
     DUTOK_IDENTIFIER = 280,
     DUTOK_UINT = 281,
     DUTOK_REAL = 282,
     DUTOK_STRING = 283,
     DUTOK_SEMICOLON = 284,
     DUTOK_DOT = 285,
     DUTOK_COMMA = 286,
     DUTOK_EQ = 287,
     DUTOK_COLON = 288,
     DUTOK_LPAR = 289,
     DUTOK_RPAR = 290,
     DUTOK_DOTDOT = 291,
     DUTOK_LSBRA = 292,
     DUTOK_RSBRA = 293,
     DUTOK_ASSIGN = 294,
     DUTOK_OPER_REL = 295,
     DUTOK_OPER_SIGNADD = 296,
     DUTOK_OPER_MUL = 297,
     DUTOK_FOR_DIRECTION = 298
   };
#endif
/* Tokens.  */
#define DUTOK_PROGRAM 258
#define DUTOK_LABEL 259
#define DUTOK_CONST 260
#define DUTOK_TYPE 261
#define DUTOK_VAR 262
#define DUTOK_BEGIN 263
#define DUTOK_END 264
#define DUTOK_PROCEDURE 265
#define DUTOK_FUNCTION 266
#define DUTOK_ARRAY 267
#define DUTOK_OF 268
#define DUTOK_GOTO 269
#define DUTOK_IF 270
#define DUTOK_THEN 271
#define DUTOK_ELSE 272
#define DUTOK_WHILE 273
#define DUTOK_DO 274
#define DUTOK_REPEAT 275
#define DUTOK_UNTIL 276
#define DUTOK_FOR 277
#define DUTOK_OR 278
#define DUTOK_NOT 279
#define DUTOK_IDENTIFIER 280
#define DUTOK_UINT 281
#define DUTOK_REAL 282
#define DUTOK_STRING 283
#define DUTOK_SEMICOLON 284
#define DUTOK_DOT 285
#define DUTOK_COMMA 286
#define DUTOK_EQ 287
#define DUTOK_COLON 288
#define DUTOK_LPAR 289
#define DUTOK_RPAR 290
#define DUTOK_DOTDOT 291
#define DUTOK_LSBRA 292
#define DUTOK_RSBRA 293
#define DUTOK_ASSIGN 294
#define DUTOK_OPER_REL 295
#define DUTOK_OPER_SIGNADD 296
#define DUTOK_OPER_MUL 297
#define DUTOK_FOR_DIRECTION 298




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




