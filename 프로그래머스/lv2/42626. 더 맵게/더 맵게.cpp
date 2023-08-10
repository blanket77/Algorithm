#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(auto n : scoville){
        pq.push(n);
    }

    while(K > pq.top() && pq.size() >= 2){
        int n1 = pq.top();  pq.pop();
        int n2 = pq.top();  pq.pop();
        pq.push(n1 + 2*n2);

        answer++;
    }

    if(K > pq.top())
        return -1;


    return answer;
}