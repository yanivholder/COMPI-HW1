#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include "tokens.hpp"
using namespace std;


extern int yylex();
string string_lexeme_proccessor(string text);

void showToken(const char *name) {
    printf("%d %s %s\n", yylineno, name, yytext);
}

void showString(){
    std::string product = string_lexeme_proccessor(std::string(yytext));
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
            case UNCLOSED_STRING:
                cout << "Error unclosed string" << endl;
                exit(0);
            // TODO: check it
            default:
                cout << "Error " << yytext[yyleng - 1] << endl;
                exit(0);
        }
	}
	return 0;
}


int hex_char_to_dec(char c){
    if (c < 123 && c > 96){
        return c-97+10;
    }
    else if (c < 91 && c > 64){
        return c-65+10;
    }
    else if (c < 58 && c > 47) {
        return c - 48;
    } else{
        return -1;
    }
}

char convert_hex_to_ascii(char big, char small){
    int new_big = hex_char_to_dec(big)*16;
    int new_small = hex_char_to_dec(small);
    if (new_big+new_small > 127){
        cout << "Error undefined escape sequence x"<<big<<small<<endl;
        exit(0);
    }
    if (new_big < 0){
        cout << "Error undefined escape sequence x" << endl;
        exit(0);
    }
    if (new_small < 0){
        cout << "Error undefined escape sequence x" << big << endl;
        exit(0);
    }

    return (char)(new_big+new_small);
}

string string_lexeme_proccessor(string text){
    string before = text;
    string after;
    before = before.substr(1, before.length()-2); //cut off ""
    for(int i=0; i < before.length(); i++){
        if (before[i] == '\\'){
            if (i+1 == before.length()){
                cout << "Error unclosed string" << endl;
                exit(0);
            }
            i++;
            switch (before[i]) {
                case '\\':
                    after+='\\';
                    break;
                case '0':
                    after+='\0';;
                    break;
                case '"':
                    after+='\"';
                    break;
                case 'n':
                    after+='\n';
                    break;
                case 'r':
                    after+='\r';
                    break;
                case 't':
                    after+='\t';
                    break;
                case 'x':
                    if(i == before.length() || i+1 == before.length()){
                        cout << "Error undefined escape sequence " << before[i] <<endl;
                        exit(0);
                    }
                    else if (i+2 == before.length()){
                        cout << "Error undefined escape sequence " << before[i] << before[i+1] <<endl;
                        exit(0);
                    }
                    after += convert_hex_to_ascii(before[i+1], before[i+2]);
                    i+=2;
                    break;
                default:
                    cout << "Error undefined escape sequence " << before[i] << endl;
                    exit(0);
            }
        } else{
            after+=before[i];
        }
    }
    return after;
}