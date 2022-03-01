%option noyywrap

%{
/* Now in a section of C that will be embedded
   into the auto-generated code. Flex will not
   try to interpret code surrounded by %{ ... %} */

/* Bring in our declarations for token types and
   the yylval variable. */
#include "histogram.hpp"


// This is to work around an irritating bug in Flex
// https://stackoverflow.com/questions/46213840/get-rid-of-warning-implicit-declaration-of-function-fileno-in-flex
extern "C" int fileno(FILE *stream);

/* End the embedded code section. */
%}


D [0-9]
C [a-zA-Z]   

F ({D}+)|({D}+"."{D}+)
Neg "-"?{F}
Fr "-"?{D}+"/"{D}+

S [/"]{C}+[/"]

 

%%


{Neg}   {yylval.numberValue = std::strtod(yytext,nullptr); return Number;}
{Fr}     {std::string tmp = yytext; double t1,t2; t1 =  std::stod(tmp.substr(0, tmp.find("/")), nullptr);  t2 = std::stod(tmp.substr(tmp.find("/")+1,tmp.size() ), nullptr); yylval.numberValue = t1/t2; return Number;}

{W}     {yylval.wordValue = new std::string; *(yylval.wordValue) = yytext; return Word;}
{S}     {yylval.wordValue = new std::string; *(yylval.wordValue) = yytext; return String;}


\n    {}
.     {}

%%

/* Error handler. This will get called if none of the rules match. */
void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  exit(1);
}
