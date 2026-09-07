#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
    stack<pair<int, int>> st;
    public:
    MinStack() {}

    void push(int val){
        if(!st.empty()){
            int currMin = min(val, st.top().second);
            st.push({val, currMin});
        }else{
            st.push({val, val});
        }
    }

    int top(){
        return st.top().first;
    }

    int pop(){
        int ans = -1;
        if(!st.empty()){
            ans = st.top().first;
            st.pop();
        }
        return ans;
    }
    

    int getMin(){
        if(!st.empty()){
            return st.top().second;
        }
        return -1;
    }
};