#include <string>
#include <vector>
#include <queue>

using namespace std;

void init_q(queue<int>& qq, vector<int>& t){
    for(int i = 0 ; i < t.size(); i++){
        qq.push(t[i]);
    }
}

int how_long(queue<int> q){
    int len = q.size();
    
    int basis = q.front();
    q.pop();

    int count = 1;
    while(!q.empty()){
        if(basis <= q.front()){
            count++;
        }
        else{
            count++;
            break;
        }
        q.pop();
    }

    if(count == 1){
        return len - count;
    }

    return count-1;
}

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    queue<int> pri;

    init_q(pri, prices);
    
    while(!pri.empty()){
        answer.push_back(how_long(pri));
        pri.pop();
    }

    return answer;
}