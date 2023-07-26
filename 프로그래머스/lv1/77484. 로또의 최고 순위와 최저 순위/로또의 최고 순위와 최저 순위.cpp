#include <string>
#include <vector>

using namespace std;

int ranks(int a){
    if(a >= 2)
        return 7-a;
    else
        return 6;    
}

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

    answer.push_back(ranks(count+zerocount));
    answer.push_back(ranks(count));

    return answer;
}