#include<string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    vector <bool> Bracket;

    for(char c : s){
        if(c == '(')
            Bracket.push_back(true);
        else{
            if(Bracket.empty()){
                answer = false;
                break;
            }

            else    
                Bracket.pop_back();
        }
    }

    if(!Bracket.empty())
        answer = false;

    return answer;
}