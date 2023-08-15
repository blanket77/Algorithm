#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int answer = INT_MAX;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1}; //동서남북
int de_point;

void dfs(int x, int y, int count, const vector<vector<int>>& m, vector<vector<bool>> &vist){
    if(x < 0 || y < 0 || x >= de_point || y >= de_point || vist[x][y] || !m[x][y])
        return;

    vist[x][y] = true;
    count++;
    if(x == de_point && y == de_point){
        answer = min(answer, count);
        return;
    }
    
    for(int i = 0; i < 4 ; i++)
        dfs(x+dx[i], y+dy[i] ,count, m, vist); 
}

int solution(vector<vector<int> > maps)
{
    de_point = maps.size()-1;
    vector<bool> v(maps.size(), false);
    vector<vector<bool>> visited;
    for(int i = 0 ; i < maps.size(); i++){
        visited.push_back(v);       
    }
    dfs(0,0,0,maps, visited);
    return answer;
}