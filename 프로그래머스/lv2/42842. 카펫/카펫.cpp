#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;

    for(int i = 2 ; i <= sum/2; i++){
        if(sum % i == 0){
            int m = sum/i;
            int n = i;
            if(m >= n){
                if( ( (m-2)* (n-2) == yellow ) ){
                    answer.push_back(m);
                    answer.push_back(n);
                }
            }
        }
    }

    return answer;
}