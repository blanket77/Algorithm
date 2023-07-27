#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    if('a' <= s[0] && s[0] <= 'z'){
        s[0] = s[0] - 'a' + 'A' ; 
    }
    
    for(int i = 1 ; i < s.size() ; i++){
        s[i] = tolower(s[i]); 
    }

    for(int i = 1 ; i < s.size() ; i++){
        char c = s[i];

        if(c == ' ' && s[i+1] != ' '){
            s[i+1] = s[i+1] - 'a' + 'A';
        }
    }

    answer = s;

    return answer;
}