#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end(), greater<>());

    for(int i = 0 ; i < citations.size(); i++){
        if(citations[i] < i+1){
            answer = i;
            break;
        }

        // 만약 모든 논문이 총 갯수이상 인용이 되었으면 
        if(i == citations.size()-1){
            answer = citations.size();
        }
    }
    

    return answer;
}