#include<vector>
#include<climits>
#include<algorithm>
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int answer = INT_MAX;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,-1,1}; //북남서동
int de_point_Y;
int de_point_X;

void bfs(int y, int x, int count, const vector<vector<int>>& m, vector<vector<bool>> &vist){
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0,0,1));
    vist[0][0] = true;
    
    while(!q.empty()){
        int Y = get<0>(q.front());
        int X = get<1>(q.front());
        int count = get<2>(q.front());

        q.pop();

        //cout << Y << " " << X << endl;

        if(Y == de_point_Y-1 && X == de_point_X-1){
            answer = count;
            break;
        }

        for(int i = 0 ; i < 4; i++){
            int ny = Y+dy[i]; int nx = X+dx[i];

            if(nx >= 0 && ny >= 0 && nx < de_point_X && ny < de_point_Y){
                if(!vist[ny][nx] && m[ny][nx]){
                    q.push(make_tuple(ny,nx, count+1));
                    vist[ny][nx] = true;
                }
            }
        }
    }
}


int solution(vector<vector<int> > maps){
    de_point_Y = maps.size();
    de_point_X = maps[0].size();

    vector<bool> v(de_point_X, false);
    vector<vector<bool>> visited;
    for(int i = 0 ; i < de_point_Y; i++){
        visited.push_back(v);       
    }
    bfs(0,0,0,maps, visited);

    if(answer == INT_MAX)
        answer = -1;

    return answer;
}

int main(){
    solution({{1,0,0,0},{1,1,1,1},{0,0,0,1}});
    //cout << answer;
}