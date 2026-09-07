#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include "Infix2Prefix.cpp"
using namespace std;

int main(){
    
    vector<pair<string, string>> testCases = {
        {"a+b", "+ab"},
        {"a+b*c", "+a*bc"},
        {"(a+b)*c", "*+abc"},
        {"a+b*(c^d+e)", "+a*b+^cde"}    
    };
    
    for(const auto& [input, expected] : testCases){

        string res = infixToPrefix(input);
        if(res == expected){
            cout << "Test Passed" << endl;
        }else{
            cout << "Test Failed";
            cout<<endl;
            cout << "Expected: " << expected <<endl;
            cout << " Got: " << res <<endl;
        }
    }
    
}