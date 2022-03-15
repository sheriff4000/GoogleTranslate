%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "parser.tab.hpp"
%}



D [0-9] // DIGIT
L [a-zA-Z]  // LETTER

I ({D}+)
F ({D}+"."{D}+)
NegF "-"?{F}
NegI "-"?{I}
Fr "-"?{D}+"/"{D}+

S \"[{C}{D}]+\"



%%

/* OPERATORS */
"*"            { return('*'); }
"/"            { return('/'); }
"+"             { return('/'); }
"-"             { return('-'); }
"&&"            { return AND; }
"||"            {return OR;}
"!"            {return NOT;}
"&"            {return B_AND;}
"|"           {return B_OR;}
"^"            {return B_XOR;}
"~"           {return B_NOT;}
"<<"         {return B_LSL;}
">>"            {return B_LSR;}

/* EQ OPERATORS */



/* BRACKETS */
"("             { return('('); }
")"             { return(')'); }
"{"             { return('{'); }
"}"             { return('}'); }
\[            { return('['); }
\]            { return(']'); }



[=]             { return EQUALS; }



"int"           { return T_INT; }
"float"         { return T_FLOAT; }
"double"        {return T_DOUBLE;}
"char"          {return T_CHAR;}
"short"         {return T_SHORT;}
"void"			    { return T_VOID; }

"break"			    { return BREAK;}
"while"			    { return WHILE;}
"if"			      { return IF; }
"case"			    { return CASE;}
"default"		    { return DEFAULT; }


"else"			    { return ELSE;}
"continue"	    { return CONTINUE; }
"do"			      { return DO ; }
"return"		    { return RETURN;}
"for"			      { return FOR; }
"unsigned"	    { return UNSIGNED;}
"switch"		    { return SWITCH; }
"enum"			    { return ENUM; }
"typedef"		    { return TYPEDEF; }
"volatile"	    { return VOLATILE; }
"struct"		    { return STRUCT; }

sizeof          { return OP_SIZEOF; }


{NegI}                     { yylval.number=strtod(yytext, 0); return INT_LITERAL; }
{NegF}                     { yylval.number=strtod(yytext, 0); return FLOAT_LITERAL; }
[{C}\_][{C}\_0-9]*        { yylval.string=new std::string(yytext); return IDENT; }
{S}                        {yylval.string = new std::string; *(yylval.string) = yytext; return STRING_LITERAL;}
{Fr}                       {std::string tmp = yytext; double t1,t2; t1 =  std::stod(tmp.substr(0, tmp.find("/")), nullptr);  t2 = std::stod(tmp.substr(tmp.find("/")+1,tmp.size() ), nullptr); yylval.number = t1/t2; return DOUBLE_LITERAL;}




[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
