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
                if (p_vec[p_vec.size() - 1] != "{") {
                    cout << "Error: Bad Expression" << endl;
                    exit(0);
                } else {
                    p_vec.pop_back();
                    print_tabs(p_vec.size());
                    cout << "}" << endl;
                }
                break;
            case ERROR:
                cout << "Error " << yytext[yyleng - 1] << endl;
                exit(0);
            default:
                cout << "Error: " << yytext << endl;
                exit(0);
        }
	}
	return 0;
}
