#include <iostream>
#include <string>

using namespace std;

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
    if (big < 0 || small < 0){
        cout << "Error undefined escape sequence x"<<big<<small<<"\\n"<<endl;
        exit(0);
    }
    return (char)(new_big+new_small);
}

string string_lexeme_proccessor(string yytext){
    string before = yytext;
    string after;
    before = before.substr(1, before.length()-2); //cut off ""
    for(int i=0; i < before.length(); i++){
        if (before[i] == '\\'){
            if (i+1 == before.length()){
                cout << "Error unclosed string\\n" << endl;
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
                    if(i+1 == before.length()){
                        cout << "Error undefined escape sequence " << before[i] <<endl;
                        exit(0);
                    }
                    after += convert_hex_to_ascii(before[i+1], before[i+2]);
                    i+=2;
                    break;
                default:
                    cout << "Error undefined escape sequence " << before[i] << "\\n" << endl;
                    exit(0);
            }
        } else{
            after+=before[i];
        }
    }
    return after;
}