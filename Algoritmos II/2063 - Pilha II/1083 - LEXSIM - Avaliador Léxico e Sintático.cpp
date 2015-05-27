#include <iostream>
#include <stack>
#include <map>

/* 20 % error
 *
 * Errors Examples:
 * b)+(a
 * a+(b)
 */
 

#define TYPE_NONE 0
#define TYPE_LETTER 1
#define TYPE_NUM 2
#define TYPE_OPERATOR 3
#define TYPE_OTHER 4
 
using namespace std;
 
int lexCheck(char c) {
    if (isalpha(c)) {
        return TYPE_LETTER;
    } else if (isdigit(c)) {
        return TYPE_NUM;
    } else if (c == '(' or c == ')') {
        return TYPE_OTHER;
    } else if (c == '^' or c == '*' or c == '/' or c == '+' or c == '-' or c == '>' or c == '<' or c == '=' or c == '#' or c == '.' or c == '|') {
        return TYPE_OPERATOR;
    }
     
    return TYPE_NONE;
}
 
int main() {
    map<char, int> prior = {{'^', 6}, {'*', 5}, {'/', 5}, {'+', 4}, {'-', 4}, {'>', 3}, {'<', 3}, {'=', 3}, {'#', 3}, {'.', 2}, {'|', 1}};
    string line;
     
    while(cin >> line) {
        string errorMsg = "", equation = "";
        bool showError = false;
        int lastCheck = lexCheck(line[0]);
        stack<int> pilha;
         
        for (int i = 0; line[i] != '\0'; i++) {
            char c = line[i];
             
            if (i > 0) {
                int curCheck = lexCheck(c);
                 
                if (curCheck == lastCheck) {
                    showError = true;
                    errorMsg = "Syntax Error!\n";
                    break;
                } else {
                    lastCheck = curCheck;
                }
            }
             
            if (not (isalnum(c) or (prior.find(c) != prior.end()) or c == '(' or c == ')')) {
                showError = true;
                errorMsg = "Lexical Error!\n";
                break;
            } else {
                if (prior[c] > 0 or c == '(' or c == ')') {
                    if (pilha.size() == 0 or c == '(') {
                        pilha.push(c);
                    } else if (c == ')'){
                        while(pilha.size() > 0 and pilha.top() != '(') {
                            equation += pilha.top();
                            pilha.pop();
                        }
                         
                        pilha.pop();
                    } else {
                        while (pilha.size() > 0 and prior[c] <= prior[pilha.top()]) {
                            equation += pilha.top();
                            pilha.pop();
                        }
                         
                        pilha.push(c);
                    }
                } else {
                    equation += c;
                }
            }
        }
         
        if (not (showError)) {
            while (pilha.size() > 0) {
                if (pilha.top() == '(') {
                    showError = true;
                    errorMsg = "Syntax Error!\n";
                }
                 
                equation += pilha.top();
                pilha.pop();
            }
        }
         
        if (not (showError)) {
            cout << equation << endl;
        } else {
            cout << errorMsg;
        }
    }
 
    return 0;
}
