#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, bool> m;

    for(auto s : phone_book){
        m.insert({s , true });
    }

    bool ch = false;
    for(auto s : phone_book){
        for(int i = 1 ; i <= s.size()-1; i++){
            string sub = s.substr(0, i);
            if(m.find(sub) != m.end()){
                answer = false;
                ch = true;
                break;
            }
        }
        if(ch) break;
    }
    

    return answer;
}