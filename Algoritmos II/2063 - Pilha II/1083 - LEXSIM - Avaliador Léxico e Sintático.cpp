#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <map>
 
using namespace std;
 
int main(){
    map<char, int> prioridade;
    prioridade['^'] = 6;
    prioridade['*'] = 5;
    prioridade['/'] = 5;
    prioridade['+'] = 4;
    prioridade['-'] = 4;
    prioridade['>'] = 3;
    prioridade['<'] = 3;
    prioridade['='] = 3;
    prioridade['#'] = 3;
    prioridade['.'] = 2;
    prioridade['|'] = 1;
    prioridade['('] = 0;
 
    string exp;
 
    while(getline(cin, exp)){
        stack<char> s;
        string pos = "";
        bool lexi_error = false;
        bool sint_error = false;
 
        for(int i=0; exp[i]!='\0'; i++){
            char ch = exp[i];
 
            if(isalnum(ch)){
                if(i == 0 or !isalnum(exp[i-1])){
                    pos += ch;
                } else {
                    sint_error = true;
                    break;
                }
            } else if(ch == '('){
                s.push(ch);
            } else if(ch == ')'){
                while(!s.empty() and s.top() != '('){
                    pos += s.top();
                    s.pop();
                }
 
                if(!s.empty()){
                    s.pop();
                } else {
                    sint_error = true;
                    break;
                }
            } else if(prioridade.count(ch)){
                while(!s.empty() and prioridade[s.top()] >= prioridade[ch]){
                    pos += s.top();
                    s.pop();
                }
 
                s.push(ch);
            } else {
                lexi_error = true;
                break;
            }
        }
 
        while(!s.empty() and s.top() != '('){
            pos += s.top();
            s.pop();
        }
 
        if(!s.empty()){
            sint_error = true;
        }
 
        stack<string> valid;
 
        if(!lexi_error and !sint_error){
            pos += '\0';
 
            for(int i=0; pos[i]!='\0'; i++){
                char ch = pos[i];
 
                if(isalnum(ch)){
                    string temp = "" + ch;
                    valid.push(temp);
                } else {
                    string var1, var2;
 
                    if(!valid.empty()){
                        var2 = valid.top();
                        valid.pop();
                    } else {
                        sint_error = true;
                        break;
                    }
 
                    if(!valid.empty()){
                        var1 = valid.top();
                        valid.pop();
                    } else {
                        sint_error = true;
                        break;
                    }
 
                    valid.push(var1 + ch + var2);
                }
            }
 
            if(valid.size() != 1){
                sint_error = true;
            }
        }
 
        if(lexi_error){
            printf("Lexical Error!\n");
 
        } else if(sint_error){
            printf("Syntax Error!\n");
 
        } else {
            printf("%s\n", pos.c_str());
        }
    }
    
    return 0;
}
