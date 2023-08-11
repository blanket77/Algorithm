#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    sort(dungeons.begin(), dungeons.end());
    do{
        int fatigue = k;
        int count = 0;

        for(auto n : dungeons){
            if(fatigue >= n[0]){
                fatigue -= n[1];
                count++;
            }
        }

        answer = max(answer, count);
    }while(next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}

int main(){
    solution(80, {{80,20},{50,40},{30,10}});
}