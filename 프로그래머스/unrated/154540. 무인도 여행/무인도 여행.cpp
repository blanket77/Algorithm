#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int x_len, y_len, sum=0;
bool visited[100][100] = {false, };

bool In_range(int x, int y){
    if( 0 <= x && x < x_len && 0 <= y && y < y_len)
        return true;
    return false;
}

void dfs(int x, int y, const vector<string>& maps){
    sum += maps[x][y] - '0';
    visited[x][y] = true;

    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(In_range(nx, ny) && !visited[nx][ny] && !(maps[nx][ny] == 'X'))
            dfs(nx,ny,maps);
    }
}


vector<int> solution(vector<string> maps) {
    x_len = maps.size();
    y_len = maps[0].size();

    for(int i = 0 ; i < x_len; i++){
        for(int j = 0 ; j < y_len ; j++){
            if(!(maps[i][j] == 'X') && !visited[i][j]){
                dfs(i,j,maps);
                answer.push_back(sum);
                sum = 0; // sum 초기화
            }
        } 
    }
    sort(answer.begin(), answer.end());
    if(answer.empty())
        answer.push_back(-1);

    return answer;
}

int main(){
    solution({"X591X","X1X5X","X231X", "1XXX1"});
}