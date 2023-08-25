#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <climits>
#include <algorithm>
using namespace std;

int visited[1000001] = {0,};
int answer = INT_MAX;

void dfs(const int& x, const int& y, const int& n, int count){
    if(x > y) return;
    
    if(visited[x] != 0){
        if(count < visited[x]) visited[x] = count;
        else return;
    } // 이미 나온 숫자고 더 오래 걸려서 나온 거면 skip!!


    if(x == y)
        answer = min(answer, count);

    dfs(x+n, y, n, count+1);
    dfs(x*2, y, n, count+1);
    dfs(x*3, y, n, count+1);
}

int solution(int x, int y, int n) {

    dfs(x,y,n,0);

    if(answer == INT_MAX)
        answer = -1;

    return answer;
}

int main(){
    solution(10,40,5);
    return 0;
}