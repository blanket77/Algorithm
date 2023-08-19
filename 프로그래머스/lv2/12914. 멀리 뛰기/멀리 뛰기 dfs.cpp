#include <string>
#include <vector>

using namespace std;

long long answer = 0;

void dfs(int sum, const int &n){
    if(sum > n)
        return;
    if(sum == n)
        answer = (answer + 1)%1234567;
    
    dfs(sum+1,n);
    dfs(sum+2,n);
}

long long solution(int n) {
    dfs(0,n);

    return answer;
}