#include <string>
#include <vector>
#include <queue>

using namespace std;

string answer = "";

void bfs(const int& n){
    queue<string> q;
    q.push("1"); q.push("2"); q.push("4");
    int cnt = 0;

    while(!q.empty()){
        string tmp = q.front();
        cnt++;
        q.pop();

        if(cnt == n){
            answer = tmp;
            return;
        }
        q.push(tmp+"1");
        q.push(tmp+"2");
        q.push(tmp+"4");       
    }
}

string solution(int n) {

    bfs(n);

    return answer;
}