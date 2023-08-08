#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for(int idx = 0 ; idx < prices.size(); idx++){
        int count = 0;
        for(int i = idx+1; i < prices.size(); i++){
            count++;
            if (prices[idx] > prices[i])
                break;
        }
        answer.push_back(count);
    }

    return answer;
}