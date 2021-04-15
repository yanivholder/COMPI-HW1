#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

#include "tokens.hpp"
using namespace std;
extern int yylex();

void print_tabs(int num)
{
    for(int i = 0; i < num; i++)
    {
        cout << "\t";
    }
}

void showTokenAndQuit(string st) {
    cout << "Error: " << st << endl;
    exit(0);
}

int main()
{
	int token;
	std::vector<std::string> p_vec;

	while(token = yylex()) {
        switch (token) {
            case LPAREN:
                print_tabs(p_vec.size());
                cout << "(" << endl;
                p_vec.emplace_back("(");
                break;
            case LBRACE:
                print_tabs(p_vec.size());
                cout << "{" << endl;
                p_vec.emplace_back("{");
                break;
            case RPAREN:
                if (p_vec.empty()) {
                    cout << "Error: Bad Expression" << endl;
                    exit(0);
                }
                if (p_vec[p_vec.size() - 1] != "(") {
                    cout << "Error: Bad Expression" << endl;
                    exit(0);
                } else {
                    p_vec.pop_back();
                    print_tabs(p_vec.size());
                    cout << ")" << endl;
                }
                break;
            case RBRACE:
                if (p_vec.empty()) {
                    cout << "Error: Bad Expression" << endl;
                    exit(0);
                }
                if (p_vec[p_vec.size() - 1] != "{") {
                    cout << "Error: Bad Expression" << endl;
                    exit(0);
                } else {
                    p_vec.pop_back();
                    print_tabs(p_vec.size());
                    cout << "}" << endl;
                }
                break;
            case VOID:
                showTokenAndQuit("VOID");
                break;
            case INT:
                showTokenAndQuit("INT");
                break;
            case BYTE:
                showTokenAndQuit("BYTE");
                break;
            case B:
                showTokenAndQuit("B");
                break;
            case BOOL:
                showTokenAndQuit("BOOL");
                break;
            case AND:
                showTokenAndQuit("AND");
                break;
            case OR:
                showTokenAndQuit("OR");
                break;
            case NOT:
                showTokenAndQuit("NOT");
                break;
            case TRUE:
                showTokenAndQuit("TRUE");
                break;
            case FALSE:
                showTokenAndQuit("FALSE");
                break;
            case RETURN:
                showTokenAndQuit("RETURN");
                break;
            case IF:
                showTokenAndQuit("IF");
                break;
            case ELSE:
                showTokenAndQuit("ELSE");
                break;
            case WHILE:
                showTokenAndQuit("WHILE");
                break;
            case BREAK:
                showTokenAndQuit("BREAK");
                break;
            case CONTINUE:
                showTokenAndQuit("CONTINUE");
                break;
            case SWITCH:
                showTokenAndQuit("SWITCH");
                break;
            case CASE:
                showTokenAndQuit("CASE");
                break;
            case DEFAULT:
                showTokenAndQuit("DEFAULT");
                break;
            case COLON:
                showTokenAndQuit("COLON");
                break;
            case SC:
                showTokenAndQuit("SC");
                break;
            case COMMA:
                showTokenAndQuit("COMMA");
                break;
            case ASSIGN:
                showTokenAndQuit("ASSIGN");
                break;
            case RELOP:
                showTokenAndQuit("RELOP");
                break;
            case BINOP:
                showTokenAndQuit("BINOP");
                break;
            case COMMENT:
                printf("COMMENT\n");
                break;
            case ID:
                showTokenAndQuit("ID");
                break;
            case NUM:
                showTokenAndQuit("NUM");
                break;
            case STRING:
                showTokenAndQuit("STRING");
                break;
            default:
                cout << "Error " << yytext[yyleng - 1] << endl;
                exit(0);
        }
	}
	if (!p_vec.empty()) {
        cout << "Error: Bad Expression" << endl;
        exit(0);
	}
	return 0;
}
