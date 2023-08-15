#include<vector>
#include<climits>
#include<algorithm>
#include<iostream>
using namespace std;
int answer = INT_MAX;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1}; //북남서동
int de_point_Y;
int de_point_X;

void dfs(int y, int x, int count, const vector<vector<int>>& m, vector<vector<bool>> &vist){
    //cout << y << " " << x << endl;

    vist[y][x] = true;
    count++;
    if(x == de_point_X-1 && y == de_point_Y-1){
        answer = min(answer, count);
        return;
    }
    
    for(int i = 0; i < 4 ; i++){
        int ny = y+dy[i]; int nx = x+dx[i];
        if(nx >= 0 && ny >= 0 && nx < de_point_X && ny < de_point_Y){
            if(!vist[ny][nx] && m[ny][nx]){
                dfs(ny, nx ,count, m, vist);
                vist[ny][nx] = false;
            }
        }
        
    }
}

int solution(vector<vector<int> > maps)
{
    de_point_Y = maps.size();
    de_point_X = maps[0].size();

    vector<bool> v(de_point_X, false);
    vector<vector<bool>> visited;
    for(int i = 0 ; i < de_point_Y; i++){
        visited.push_back(v);       
    }
    dfs(0,0,0,maps, visited);

    if(answer == INT_MAX)
        answer = -1;

    return answer;
}

int main(){
    solution({{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}});
    //cout << answer;
}