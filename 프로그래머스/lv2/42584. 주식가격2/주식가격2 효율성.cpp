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

    int basis = q.front();
    q.pop();

    int count = 0;
    while(!q.empty()){
        count++;
        if(basis > q.front())
            break;
        q.pop();
    }

    return count;
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

int main(){
    solution({1, 2, 3, 2, 3});
}