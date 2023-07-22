#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    int p_num = 0;
    int y_num = 0; 

    for(auto c : s){
        if(c == 'y' || c == 'Y' )
            y_num++;
        if(c == 'p' || c == 'P')
            p_num++;
    }

    if(y_num != p_num)
        answer = false;

    return answer;
}