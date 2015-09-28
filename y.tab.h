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
    INT = 258,
    FLOAT = 259,
    BOOL = 260,
    VOID = 261,
    INT_NUM = 262,
    FLOAT_NUM = 263,
    TRUE = 264,
    FALSE = 265,
    IDENTIFIER = 266,
    SEMI = 267,
    LP = 268,
    RP = 269,
    COMMA = 270,
    LCB = 271,
    RCB = 272,
    MAIN = 273,
    INPUT = 274,
    OUTPUT = 275,
    WHILE = 276,
    FOR = 277,
    IF = 278,
    IFX = 279,
    ELSE = 280,
    BREAK = 281,
    RETURN = 282,
    EQUALS = 283,
    DOUBLE_EQ = 284,
    GREATER = 285,
    GREATER_EQ = 286,
    LESS = 287,
    LESS_EQ = 288,
    NOT_EQ = 289,
    MULT = 290,
    DIV = 291,
    INCR = 292,
    DECR = 293,
    AND = 294,
    OR = 295,
    NOT = 296,
    PLUS = 297,
    MINUS = 298,
    NEGATION = 299
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define BOOL 260
#define VOID 261
#define INT_NUM 262
#define FLOAT_NUM 263
#define TRUE 264
#define FALSE 265
#define IDENTIFIER 266
#define SEMI 267
#define LP 268
#define RP 269
#define COMMA 270
#define LCB 271
#define RCB 272
#define MAIN 273
#define INPUT 274
#define OUTPUT 275
#define WHILE 276
#define FOR 277
#define IF 278
#define IFX 279
#define ELSE 280
#define BREAK 281
#define RETURN 282
#define EQUALS 283
#define DOUBLE_EQ 284
#define GREATER 285
#define GREATER_EQ 286
#define LESS 287
#define LESS_EQ 288
#define NOT_EQ 289
#define MULT 290
#define DIV 291
#define INCR 292
#define DECR 293
#define AND 294
#define OR 295
#define NOT 296
#define PLUS 297
#define MINUS 298
#define NEGATION 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
