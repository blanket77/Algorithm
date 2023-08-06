#include <string>
#include <vector>
#include <queue>

using namespace std;

int calculus_day(int a, int b){
    if(a%b == 0)
        return a/b;
    else
        return a/b+1;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> p,q;
    for(auto n : progresses){
        p.push(n);
    }
    for(auto n : speeds){
        q.push(n);
    }

    int day=0;
    int count = 0;
    while(!p.empty()){
        int num = 100 - p.front();
        if(num > day*q.front()){
            day = calculus_day(num, q.front());
            if(count != 0){
                answer.push_back(count);
                count = 0;
            }       
        }
        else{
            count++;
            p.pop(); q.pop();
        }
    }
    //마지막 answer 값은 따로 저장해야한다.
    answer.push_back(count);

    return answer;
}

int main(){
    solution({93,30,55},{1, 30, 5});
}