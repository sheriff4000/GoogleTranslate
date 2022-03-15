/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_SRC_COMPILER_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_COMPILER_PARSER_TAB_HPP_INCLUDED
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
    IDENT = 258,
    RETURN = 259,
    T_INT = 260,
    T_FLOAT = 261,
    T_DOUBLE = 262,
    T_CHAR = 263,
    T_UINT = 264,
    T_SHORT = 265,
    T_VOID = 266,
    EQUALS = 267,
    PLUS = 268,
    MINUS = 269,
    TIMES = 270,
    DIVIDE = 271,
    AND = 272,
    OR = 273,
    NOT = 274,
    B_AND = 275,
    B_OR = 276,
    B_NOT = 277,
    B_LSL = 278,
    B_LSR = 279,
    INT_LITERAL = 280,
    FLOAT_LITERAL = 281,
    STRING_LITERAL = 282,
    LBRACKET = 283,
    RBRACKET = 284,
    CLBRACKET = 285,
    CRBRACKET = 286,
    SLBRACKET = 287,
    SRBRACKET = 288,
    BREAK = 289,
    WHILE = 290,
    IF = 291,
    ELSE = 292,
    CASE = 293,
    DEFAULT = 294,
    VOID = 295,
    CONTINUE = 296,
    DO = 297,
    ENUM = 298,
    TYPEDEF = 299,
    VOLATILE = 300,
    STRUCT = 301,
    OP_SIZEOF = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "src/compiler_parser.y"

    const program *prog;


#line 110 "src/compiler_parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_COMPILER_PARSER_TAB_HPP_INCLUDED  */
