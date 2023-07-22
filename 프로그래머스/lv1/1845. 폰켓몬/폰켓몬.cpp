#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, bool> m;

    for(auto n : nums){
        m[n] = true;
    }

    int get_num = nums.size()/2;
    int po_typeNum = m.size(); 

    if(get_num <= po_typeNum){
        answer = get_num;
    }
    else
        answer = po_typeNum;

    return answer;
}