#include <string>
#include <vector>
#include <queue>
#define DEL_MIN "D -1"
#define DEL_MAX "D 1"
#define INSERT_C 'I'


using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int> pq1; // max_hip
    priority_queue<int, vector<int>, greater<int>> pq2; // min_hip

    int sizes = 0;
    for(auto s : operations){  
        if(sizes == 0){
            while(!pq1.empty())
                pq1.pop();
            while(!pq2.empty())
                pq2.pop();
        }

        if(s[0] == INSERT_C){
            int num = atoi(s.substr(2).c_str());
            pq1.push(num);
            pq2.push(num);
            sizes++;
        }
        else{
            if(s == DEL_MIN && sizes != 0){
                pq2.pop(); 
                sizes--;
            }
            else if(s == DEL_MAX && sizes != 0){
                pq1.pop();
                sizes--;
            }
            else{} // Nothing happend if sizes is zero.
        }
    }

    if(sizes == 0){
        answer.push_back(0);
        answer.push_back(0);
    }

    else{
        answer.push_back(pq1.top());
        answer.push_back(pq2.top());
    }

    return answer;
}
