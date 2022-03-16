%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "parser.tab.hpp"
%}
%{
/* DIGIT*/
/* LETTER*/
/* EXPONENTIAL*/
%}
D [0-9] 
L [a-zA-Z]  
E [eE][+-]?D+ 



S \"[{C}{D}]+\"



%%

  /* OPERATORS */
"*"            { return('*'); }
"/"            { return('/'); }
"+"             { return('/'); }
"-"             { return('-'); }
"&&"            { return(AND); }
"||"            {return(OR);}
"!"            {return(NOT);}
"&"            {return('&');}
"|"           {return('|');}
"^"            {return('^');}
"~"           {return('~');}
"<<"         {return(LSL);}
">>"            {return(LSR);}

  /* EQ OPERATORS */
"="             { return('='); }


  /* BRACKETS */
"("             { return('('); }
")"             { return(')'); }
"{"             { return('{'); }
"}"             { return('}'); }
\[            { return('['); }
\]            { return(']'); }



  /* KEYWORDS */
"int"           { return(INT); }
"float"         { return(FLOAT); }
"double"        {return(DOUBLE);}
"char"          {return(CHAR);}
"short"         {return(SHORT);}
"void"			    { return(VOID); }
"break"			    { return(BREAK);}
"while"			    { return(WHILE);}
"if"			      { return(IF); }
"case"			    { return(CASE);}
"default"		    { return(DEFAULT); }
"else"			    { return(ELSE);}
"continue"	    { return(CONTINUE); }
"do"			      { return(DO) ; }
"return"		    { return(RETURN);}
"for"			      { return(FOR); }
"unsigned"	    { return(UNSIGNED);}
"switch"		    { return(SWITCH); }
"enum"			    { return(ENUM); }
"typedef"		    { return(TYPEDEF); }
"volatile"	    { return(VOLATILE); }
"struct"		    { return(STRUCT); }
"sizeof"          { return(SIZEOF); }

  /* LITERALS */
{D}+ {yylval.number = strtol(yytext, NULL, 10); return(INT_LITERAL);}

  /* need to add hex and binary support - get a baseline first tho*/

{D}?"."{D}+{E}? {yylval.f_number = strtod(yytext, NULL); return(FLOAT_LITERAL);}

{L}({L} | {D})* {yylval.string = new std::string(yytext); return(IDENTIFIER);}



  /* IGNORE */
[ \t\r\n]+		{;}

%%

void yyerror (char const *s)
{
  fprintf (stderr, "Lexing error : %s\n", s);
  exit(1);
}
