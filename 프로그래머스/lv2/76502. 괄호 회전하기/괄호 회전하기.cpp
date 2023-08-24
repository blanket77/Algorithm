#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool check(const string &s){
    stack<char> st;
    for(auto c : s){
        if(c == '(' || c == '{' || c == '[')
            st.push(c);
        else if(!st.empty() && c == ')' && st.top() == '(')
            st.pop();
        else if(!st.empty() && c == '}' && st.top() == '{')
            st.pop();
        else if(!st.empty() && c == ']' && st.top() == '[')
            st.pop();
        else
            return false;
    }
    
    if(!st.empty())
        return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    
    if(check(s)) answer++;
    for(int i = 0 ; i < s.length()-1; i++){
        s = s.substr(1,s.length()-1) + s[0];
        if(check(s)) answer++;
    }
    
    return answer;
}

