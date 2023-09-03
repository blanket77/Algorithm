#include <string>
#include <vector>
#include <queue>

using namespace std;

long long q_sum(const vector<int> &q){
    long long sum = 0;
    for(auto n : q)
        sum += n;
    
    return sum;
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    queue<int> q1 {{begin(queue1), end(queue1)}};
    queue<int> q2 {{begin(queue2), end(queue2)}};

    long long q1_sum = q_sum(queue1);
    long long q2_sum = q_sum(queue2);

    long long max_count = queue1.size()*4;

    if((q1_sum + q2_sum) % 2 == 1)
        return -1;

    while(q1_sum != q2_sum){
        if(q1_sum > q2_sum){
            long long nn = q1.front();
            q1_sum -= nn;
            q2_sum += nn;
            q1.pop();
            q2.push(nn);
        }
        else if(q1_sum < q2_sum){
            long long nn = q2.front();
            q2_sum -= nn;
            q1_sum += nn;
            q2.pop();
            q1.push(nn);
        }
        answer++;

        if(answer == max_count)
            return -1;
    }

    return answer;
}