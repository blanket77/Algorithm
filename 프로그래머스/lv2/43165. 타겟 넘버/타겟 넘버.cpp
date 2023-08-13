#include <string>
#include <vector>

using namespace std;

int answer = 0;
vector<int> v;
int t;

void DFS(int sum, int index){
    if(index == v.size()){
        if(sum == t)
            answer++;
        return;
    }

    DFS(sum + v[index], index + 1);
    DFS(sum - v[index], index + 1);
}

int solution(vector<int> numbers, int target) {
    v = numbers;
    t = target;

    DFS(0,0);

    return answer;
}

int main(){
    solution({1,1,1,1},3);

    return 0;
}