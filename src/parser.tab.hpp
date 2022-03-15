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

#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y"


    #include "ast.hpp"

    extern nodePtr g_root;
    extern FILE *yyin;


    int yylex(void);
    void yyerror(const char *);

#line 60 "src/parser.tab.hpp"

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
    SIGNED = 267,
    UNSIGNED = 268,
    T_LONG = 269,
    EQUALS = 270,
    PLUS = 271,
    MINUS = 272,
    TIMES = 273,
    DIVIDE = 274,
    AND = 275,
    OR = 276,
    NOT = 277,
    B_AND = 278,
    B_OR = 279,
    B_NOT = 280,
    B_LSL = 281,
    B_LSR = 282,
    B_XOR = 283,
    INT_LITERAL = 284,
    FLOAT_LITERAL = 285,
    STRING_LITERAL = 286,
    DOUBLE_LITERAL = 287,
    LBRACKET = 288,
    RBRACKET = 289,
    CLBRACKET = 290,
    CRBRACKET = 291,
    SLBRACKET = 292,
    SRBRACKET = 293,
    BREAK = 294,
    WHILE = 295,
    IF = 296,
    ELSE = 297,
    CASE = 298,
    DEFAULT = 299,
    VOID = 300,
    CONTINUE = 301,
    DO = 302,
    ENUM = 303,
    TYPEDEF = 304,
    VOLATILE = 305,
    STRUCT = 306,
    OP_SIZEOF = 307,
    FOR = 308,
    SWITCH = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "src/parser.y"

    std::string* string;
    int number;
    nodePtr node;

#line 132 "src/parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */
