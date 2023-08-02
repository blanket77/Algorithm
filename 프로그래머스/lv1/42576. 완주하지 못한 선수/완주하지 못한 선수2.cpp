#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;

    for(auto s : participant)
        m[s] = 0;
    for(auto s : participant)
        m[s]++;
    
    for(auto s : completion){
        m[s]--;
    }

    map<string, int>::iterator iter;
    for(iter = m.begin() ; iter != m.end() ; iter++){
        if(iter->second != 0) answer += iter->first;
    }

    return answer;
}