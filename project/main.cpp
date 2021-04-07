#include <iostream>
#include <string>

using namespace std;
string yytext;

char hex_char_to_dec(char c){
    if (c < 123 && c > 96){
        return c-97+10;
    }
    else if (c < 91 && c > 64){
        return c-65+10;
    }
    else if (c < 58 && c > 47) {
        return c - 48;
    } else{
        return 0;
    }
}

char convert_hex_to_ascii(char big, char small){
    big = hex_char_to_dec(big)*16;
    small = hex_char_to_dec(small);
    if (big == 0 || small == 0){
        cout << "Error undefined escape sequence x"<<big<<small<<"\\n"<<endl;
        exit(0);
    }
    return big+small;
}


void string_lexeme_print(){
    string before = yytext;
    string after;
    before = before.substr(1, before.length()-1); //cut off ""
    for(int i=0; i < before.length(); i++){
        if (before[i] == '\\'){
            if (i+1 == before.length()){
                cout << "Error unclosed string\\n" << endl;
                exit(0);
            }
            i++;
            switch (before[i]) {
                case '\\':
                    after+="\\";
                    break;
                case '0':
                    after+="\0";
                    break;
                case 'n':
                    after+="\n";
                    break;
                case 'r':
                    after+="\r";
                    break;
                case 't':
                    after+="\t";
                    break;
                case 'x':
                    char c = convert_hex_to_ascii(before[i], before[i+1]);
                    i+=2;
                    after+=c;
                    break;
                default:
                    cout << "Error undefined escape sequence " << before[i] <<endl;
                    exit(0);
            }
        } else{
            after.append(reinterpret_cast<const char *>(before[i]));
        }

    }
}
#include <sstream>
int main() {

    std::cout << "Hello, World!" << std::endl;
    char x = 'b';
    std::stringstream stream;
    stream << x;
    stream >> std::hex >> x;
    //std::cin >> std::hex >> x;
    std::cout << x << std::endl;


    return 0;
}
