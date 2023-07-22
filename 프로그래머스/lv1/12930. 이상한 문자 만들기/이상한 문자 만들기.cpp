#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";

    vector<string> v;

    string word = "";
    for(int i = 0 ; i < s.length(); i++){
        if(s[i] == ' '){
            v.push_back(word);
            v.push_back(" ");
            word = "";
            continue;
        }
        word += s[i];

        if(i == s.length() -1 && s[i] != ' '){
            v.push_back(word);
        }   
    }

    for(int i = 0 ; i < v.size(); i++){
        for(int j = 0 ; j < v[i].length(); j++){
            if(j % 2 == 0)
                v[i][j] = toupper(v[i][j]);
            else
                v[i][j] = tolower(v[i][j]);
        }
    }

    for(int i = 0 ; i < v.size(); i++){
        answer += v[i];
    }
    
    
    return answer;
}

int main(){
    cout << solution("  TRy HElLo  WORLD ");
}