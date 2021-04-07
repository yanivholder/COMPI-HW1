%{

/* Declarations section */
#include "tokens.hpp"

%}

%option yylineno
%option noyywrap

%x              str
digit           ([0-9])
hex             ([0-9a-fA-F])
nonzero         ([1-9])
letter          ([a-zA-Z])
printable       ([ -!#-\[\]-~\t])
escape          (\\n|\\r|\\t|\\0|\\x{hex}{2}|\\.)

%%

void                        return VOID;
int                         return INT;
byte                        return BYTE;
b                           return B;
bool                        return BOOL;
and                         return AND;
or                          return OR;
not                         return NOT;
true                        return TRUE;
false                       return FALSE;
return                      return RETURN;
if                          return IF;
else                        return ELSE;
while                       return WHILE;
break                       return BREAK;
continue                    return CONTINUE;
\;                          return SC;
\,                          return COMMA;
\(                          return LPAREN;
\)                          return RPAREN;
\{                          return LBRACE;
\}                          return RBRACE;
\=                          return ASSIGN;
\=\=|!\=|<|>|<\=|>\=        return RELOP;
\+|-|\*|\/                  return BINOP;
\/\/.*                      return COMMENT;
{letter}({letter}|{digit})* return ID;
0|({nonzero}{digit}*)       return NUM;
\"([^\"]*)[\n|\n\r]         return STRING_ERROR;
\"(({printable}|{escape})*)\"   return STRING;
\"<EOF>                     return STRING_ERROR;
\"                          return STRING_ERROR;

[\t\r\n ]                ;
.                           return ERROR;

%%
