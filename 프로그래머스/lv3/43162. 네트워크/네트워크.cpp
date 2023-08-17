#include <string>
#include <vector>
#include <iostream>

using namespace std;

int sizes;

void dfs(int idx, const vector<vector<int>>& comp, vector<bool> &check){
    check[idx] = true;

    for(int i = 0 ; i < sizes; i++){
        if(comp[idx][i] && !check[i]){
            dfs(i, comp, check);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    sizes = n;
    vector<bool> check(n, false);

    for(int i = 0; i < n ; i++){
        if(!check[i]){
            dfs(i, computers, check);
            answer++;
        }
    }

    return answer;
}

int main(){
    cout << solution(3,{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}});
    return 0;
}