#include <string>
#include <vector>
#include <algorithm>
#define STUDENT_NUM 30+1

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<bool> s(STUDENT_NUM, false);
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    answer = n - lost.size();

    for(auto i : reserve){
        s[i] = true;
    }

    for(auto i : reserve){
        for(n = 0 ; n < lost.size(); n++){
            if(i == lost[n]){
                s[i] = false;
                lost.erase(lost.begin()+n);
                answer++;
            }
        }
    }

    for(auto i : lost){

        if(s[i-1]){
            s[i-1] = false;
            answer++;
        }

        else if(s[i+1]){
            s[i+1] = false;
            answer++;
        }
    }

    return answer;
}
