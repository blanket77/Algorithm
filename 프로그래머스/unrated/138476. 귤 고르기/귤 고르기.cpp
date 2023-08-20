#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b){
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    sort(tangerine.begin(), tangerine.end());

    int remember = tangerine[0];
    int count = 0;
    vector<pair<int,int>> v;
    for(int i = 0 ; i < tangerine.size(); i++){
        if(remember == tangerine[i])
            count++;
        else{
            v.push_back({remember,count});
            count = 1; remember = tangerine[i];
        }
    }
    v.push_back({remember,count});
    
    sort(v.begin(), v.end(), compare);
    
    int sum = 0;
    int answer = 0;

    if(k == 0)  return 0;

    for(auto n : v){
        sum += n.second;
        answer++;
        if(sum >= k)
            break;
    }

    return answer;
}

int main(){
    solution(6,{1, 3, 2, 5, 4, 5, 2, 3});
}