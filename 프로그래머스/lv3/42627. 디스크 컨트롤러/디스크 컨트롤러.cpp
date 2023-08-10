#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    // jobs에 적혀있는 요청 받은 시간을 내림차순한다.
    for(auto n : jobs)
        pq.push({n[0], n[1]});
    
    // 해당 시간동안 요청들어온 것을 넣어둔 배열이다. 걸리는 시간을 내림차순하기 위해서
    // {걸리는 시간, 요청 받은 시간}으로 해두었다.
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq_call;
    int time = pq.top().first; // 처음 요청 받은 시간으로 초기화한다.

    int count = 0;
    //모두 다 작업할 때까지 한다.
    while(count != jobs.size()){
        //작업이 종료되었지만 요청 받은 것이 없을 때는 요청 받을 때까지 기다린다.
        //그 시간은 작업하지 않는 작업 중 제일 작은 요청받은 시간이다.
        if(!pq.empty() && time < pq.top().first && pq_call.empty()){
            time = pq.top().first;
        }

        //작업할게 있고 해당시간동안 응답 받은 것을 pq_call에 넣는다. {걸리는 시간, 요청 받은 시간}
        while(time >= pq.top().first && !pq.empty()){
            pq_call.push({pq.top().second, pq.top().first}); 
            pq.pop(); 
        }
        //걸리는 시간이 적을 것을 하나 작업한다.
        if(!pq_call.empty()){
            time += pq_call.top().first; //작업 후 시간 = 걸린 시간 + 원래 시간
            answer += time - pq_call.top().second; // total = 이전 total + (작업 후 시간 - 요청 받은 시간)
            count++;
            pq_call.pop();
        }
    }
    
    answer /= jobs.size();

    return answer;
}

int main(){
    solution({{0, 6}, {2, 8}, {3, 7}, {7, 1}, {11, 11}, {19, 25}, {30, 15}, {32, 6}, {40, 3}});

}