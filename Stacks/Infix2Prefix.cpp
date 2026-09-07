#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

    bool isAlpha(char ch){
        return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'));
    }
    
    int isPre(char ch){
        if(ch == '^'){
            return 3;
        }else if(ch == '*' || ch == '/'){
            return 2;
        }else if(ch == '+' || ch == '-'){
            return 1;
        }
        return -1;
    }
    
    bool isOperator(char ch){
        switch(ch){
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                return true;
        }
        return false;
    }
    
    string infixToPrefix(const string &s) {
        // code here
        int n = s.length();
        stack<char> st;
        string res = "";
        for(int i = n-1;i >= 0; i--){
            
            if(isAlpha(s[i])){
                res += s[i];
                
            }else if(s[i] == ')'){
                st.push(s[i]);
            }else if(s[i] == '('){
                while(!st.empty() && (st.top() != ')')){
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }else if(isOperator(s[i])){
                while(!st.empty() &&
                            st.top() != ')' &&
                            (
                                isPre(st.top()) > isPre(s[i]) ||
                                (isPre(st.top()) == isPre(s[i]) && s[i] == '^')
                            )){
                    res += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }