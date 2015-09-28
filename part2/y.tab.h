/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BIN_OPERATOR = 258,
    PLUS = 259,
    MINUS = 260,
    MULT = 261,
    DIV = 262,
    DOUBLE_EQ = 263,
    GREATER = 264,
    LESS = 265,
    EQUALS = 266,
    NEGATION = 267,
    GO_TO = 268,
    PARAM = 269,
    LABEL = 270,
    IF = 271,
    IDENTIFIER = 272,
    NUMBER1 = 273,
    NUMBER2 = 274,
    OUTPUT = 275,
    CALL = 276,
    NEWLINER = 277,
    COMMA = 278
  };
#endif
/* Tokens.  */
#define BIN_OPERATOR 258
#define PLUS 259
#define MINUS 260
#define MULT 261
#define DIV 262
#define DOUBLE_EQ 263
#define GREATER 264
#define LESS 265
#define EQUALS 266
#define NEGATION 267
#define GO_TO 268
#define PARAM 269
#define LABEL 270
#define IF 271
#define IDENTIFIER 272
#define NUMBER1 273
#define NUMBER2 274
#define OUTPUT 275
#define CALL 276
#define NEWLINER 277
#define COMMA 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
