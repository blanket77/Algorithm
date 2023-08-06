#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void init_q(queue<int>& q, int size){
    for(int i = 0 ;  i < size; i++){
        q.push(i);
    }
}

int maxInqueue(queue<int> q){
    int maxs = 0;
    if(!q.empty())
        q.pop();

    while(!q.empty()){
        if(maxs < q.front())
            maxs = q.front();
        q.pop();
    }
    return maxs;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> ans;
    queue<int> q, prior;

    init_q(q, priorities.size());
    for(auto n : priorities)
        prior.push(n);
    
    while(!q.empty()){
        int cur_q = q.front();
        int cur_p = prior.front();
        if(cur_p >= maxInqueue(prior)){
            ans.push_back(cur_q);
            q.pop(); prior.pop();
        }
        else{
            q.pop(); prior.pop();
            q.push(cur_q); prior.push(cur_p);
        }
    }
    answer = find(ans.begin(), ans.end(), location) - ans.begin() + 1;

    return answer;
}

int main(){
    solution({2, 1, 3, 2},2);
}