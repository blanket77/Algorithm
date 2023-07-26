#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    vector<bool> m(46, false);

    for(auto i : win_nums){
        m[i] = true;
    }

    int count = 0;
    int zerocount = 0;

    for(auto i : lottos){
        if(m[i])
            count++;
        
        if(i == 0)
            zerocount++;
    }

    if(count+zerocount >= 2)
        answer.push_back(7-(count+zerocount));
    else
        answer.push_back(6);

    if(count >= 2)
        answer.push_back(7-count);
    else
        answer.push_back(6);



    return answer;
}