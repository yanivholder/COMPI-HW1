#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

#include "tokens.hpp"
#include "utils.h"

void showToken(const char *name) {
    printf("%d %s %s\n", yylineno, name, yytext);
}

void showString(){
    std::string product = string_lexeme_proccessor(yytext);
    printf("%d STRING %s\n", yylineno, product.c_str());
}

int main()
{
	int token;
	while(token = yylex()) {
        switch (token) {
            case VOID:
                showToken("VOID");
                break;
            case INT:
                showToken("INT");
                break;
            case BYTE:
                showToken("BYTE");
                break;
            case B:
                showToken("B");
                break;
            case BOOL:
                showToken("BOOL");
                break;
            case AND:
                showToken("AND");
                break;
            case OR:
                showToken("OR");
                break;
            case NOT:
                showToken("NOT");
                break;
            case TRUE:
                showToken("TRUE");
                break;
            case FALSE:
                showToken("FALSE");
                break;
            case RETURN:
                showToken("RETURN");
                break;
            case IF:
                showToken("IF");
                break;
            case ELSE:
                showToken("ELSE");
                break;
            case WHILE:
                showToken("WHILE");
                break;
            case BREAK:
                showToken("BREAK");
                break;
            case CONTINUE:
                showToken("CONTINUE");
                break;
            case SWITCH:
                showToken("SWITCH");
                break;
            case CASE:
                showToken("CASE");
                break;
            case DEFAULT:
                showToken("DEFAULT");
                break;
            case COLON:
                showToken("COLON");
                break;
            case SC:
                showToken("SC");
                break;
            case COMMA:
                showToken("COMMA");
                break;
            case LPAREN:
                showToken("LPAREN");
                break;
            case RPAREN:
                showToken("RPAREN");
                break;
            case LBRACE:
                showToken("LBRACE");
                break;
            case RBRACE:
                showToken("RBRACE");
                break;
            case ASSIGN:
                showToken("ASSIGN");
                break;
            case RELOP:
                showToken("RELOP");
                break;
            case BINOP:
                showToken("BINOP");
                break;
            case COMMENT:
                printf("%d COMMENT //\n", yylineno);
                break;
            case ID:
                showToken("ID");
                break;
            case NUM:
                showToken("NUM");
                break;
            case STRING:
                showString();
                break;
            // TODO: add all of the errors types
//            case STRING_ERROR:
//                cout << "Error unclosed string" << endl;
//                exit(0);
            // TODO: check it
            default:
                cout << "Error " << yytext[yyleng - 1] << endl;
                exit(0);
        }
	}
	return 0;
}