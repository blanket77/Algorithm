#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[3000001] = {false,};
int answer = INT_MAX;

int bfs(const int& x, const int& y, const int& n){
    visited[x] = true;

    queue<pair<int, int>> q;    
    q.push({x,0}); 

    while(!q.empty()){
        int num = q.front().first;
        int count = q.front().second;
        q.pop();

        if(num == y)
            return count;
        else if(num < y){
            int a = num + n;
            if( !visited[a]) {
                q.push({a,count+1});
                visited[a] = true;
            }
            int b = 2*num;
            if(!visited[b]) {
                q.push({b,count+1});
                visited[b] = true;
            }
            int c = 3*num;
            if(!visited[c]) {
                q.push({c,count+1});
                visited[c] = true;
            }
        }    

    }
    return -1;
}

int solution(int x, int y, int n) {

    answer = bfs(x,y,n);

    return answer;
}

int main(){
    solution(10,40,5);
    return 0;
}