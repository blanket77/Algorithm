#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    map<int, string> rank_name;
    map<string, int> name_rank;
    
    for(int i = 0 ; i < players.size(); i++){
        name_rank[players[i]] = i+1;
        rank_name[i+1] = players[i];
    }
    
    for(auto call_name : callings){
        int call_inx = name_rank[call_name]; // 호출 인덱스
        string front_name = rank_name[call_inx - 1]; // 앞선 사람 이름
        
        rank_name[call_inx - 1] = call_name;
        rank_name[call_inx] = front_name;
        
        name_rank[front_name] = call_inx;
        name_rank[call_name] = call_inx-1;
    }
    
    for(auto n : rank_name){
        answer.push_back(n.second);
    }
    
    return answer;
}