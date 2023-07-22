#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if(s.length() != 4 && s.length() != 6)
        answer = false;
    
    for(auto c : s){
        if(!('0' <= c && c <= '9')){
            answer = false;
            break;
        }
    }

    return answer;
}