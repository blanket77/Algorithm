#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> m;

    for(auto v : clothes){
        string s = v[1];
        if(m.find(s) != m.end())
            m[s]++;
        else    
            m.insert({s,1});
    }

    for(auto i : m){
        answer *= (i.second+1);
    }


    return --answer;
}
