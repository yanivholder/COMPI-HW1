%{

/* Declarations section */
#include "tokens.hpp"

%}

%option yylineno
%option noyywrap

digit           ([0-9])
hex             ([0-9a-fA-F]{2})
nonzerodigit    ([1-9])
letter          ([a-zA-Z])
escape          (\\\\|\\\"|\\n|\\r|\\t|\\0|\\x(hex))
escapechar      ([\\\"nrt0]|x(hex))
illegalescape   (\\[^\\nrt0(x(hex))])
whitespace      ([\t\n ])

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
switch                      return SWITCH;
case                        return CASE;
default                     return DEFAULT;
:                           return COLON;
;                           return SC;
,                           return COMMA;
\(                          return LPAREN;
\)                          return RPAREN;
\{                          return LBRACE;
\}                          return RBRACE;
=                           return ASSIGN;
==|!=|<|>|<=|>=             return RELOP;
\+|\-|\*|\/                 return BINOP;
\/\/[^\n\r]*                return COMMENT;
{letter}({letter}|{digit})* return ID;
0|({nonzerodigit}{digit}*)  return NUM;
\"([^\\\"\n\r]|{escape})*\" return STRING;
\"([^\\\"\n\r]|{escape})*\n return UNCLOSED_STRING;




[\t\r\n ]                ;


.                           return ERROR;

%%
