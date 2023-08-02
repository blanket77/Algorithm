#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> m;

    for(auto s : participant){
        if(m.find(s) != m.end())
            m[s]++;
        else
            m.insert({s,1});
    }

    for(auto s : completion)
        m[s]--;
    

    for(auto tt : m){
        if(tt.second != 0) answer += tt.first;
    }

    return answer;
}