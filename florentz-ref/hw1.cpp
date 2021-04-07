#include <cstdio>
#include <cstdlib>
#include "tokens.hpp"
#include <string>
#include <vector>
#include <iostream>


using namespace std;


extern int yylex();

int getHexNum(const string& hexString){
    if(hexString.length() != 2){
        cout << "Error undefined escape sequence x" << hexString <<endl;
        exit(0);
    }
    int res;
    try {
        res = stoi(hexString, nullptr, 16);
    }
    catch(const std::exception& e){
        cout << "Error undefined escape sequence x" << hexString <<endl;
        exit(0);
    }
    if(res > 0x7f){
        cout << "Error undefined escape sequence x" << hexString <<endl;
        exit(0);
    }
    return res;
}


void showToken(const char *name) {
    printf("%d %s %s\n", yylineno, name, yytext);
}

void showString() {
    string iterateText = yytext + 1;
    // first and last are "
    iterateText = iterateText.substr(0, iterateText.length() - 1);
    string resultText;
    if (iterateText.back() == '\\' and (iterateText[iterateText.length() -2] != '\\')) {
        cout << "Error unclosed string" << endl;
        exit(0);
    }
    //cout << "ofir" << yytext << endl;
    for(int i = 0; i < iterateText.length(); i++){
        if((iterateText[i]) == '\\'){
            switch(iterateText[i+1]){
                case 'n':
                    resultText += '\n';
                    i++;
                    break;
                case 'r':
                    resultText += '\r';
                    i++;
                    break;
                case 't':
                    resultText += '\t';
                    i++;
                    break;
                case '"':
                    resultText += '"';
                    i++;
                    break;
                case '\\':
                    resultText += '\\';
                    i++;
                    break;
                case '0':
                    resultText += '\0';
                    i++;
                    break;
                case 'x':
                    if(i+2 > iterateText.length()){
                        cout << "Error undefined escape sequence x" << iterateText[i+1] <<endl;
                        exit(0);
                    }
                    resultText += (char) getHexNum(iterateText.substr(i+2, 2));
                    i += 3;
                    break;
                default:
                    cout << "Error undefined escape sequence " << iterateText[i+1] <<endl;
                    exit(0);
            }
        }
        else{
            resultText += iterateText[i];
        }
    }

    printf("%d STRING %s\n", yylineno, resultText.c_str());
}

int main() {
    int token;
    while ((token = yylex())) {
      //cout << "ofir " << yytext << endl;
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
            case SC:
                showToken("SC");
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
            case COMMA:
                showToken("COMMA");
                break;
            case STRING_ERROR:
                cout << "Error unclosed string" << endl;
                exit(0);
            default:
                cout << "Error " << yytext[yyleng - 1] << endl;
                exit(0);
        }
    }
    return 0;
}
