#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;

    stack<char> st;
    
    for(auto c : s){
        if(!st.empty()){
            if(st.top() == c){
                st.pop();
            }
            else
                st.push(c);
        }
        else{
            st.push(c);
        }
    }

    if(st.empty())
        answer = 1;


    return answer;
}