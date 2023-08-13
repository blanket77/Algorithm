#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());


    int idx = 0;
    while(people.size() > idx){
        int weight = people[idx] + people.back();   
        if(weight > limit)
            people.pop_back();
        else{
            people.pop_back();
            idx++;
        }
        answer++;
    }

    return answer;
}
