#include <string>
#include <vector>

using namespace std;

bool visted[101] = {false, };
bool maps[101][101] = {false, };

void draw_maps(const vector<vector<int>>& wires){
    for(auto &v : wires){
        int a = v[0];
        int b = v[1];
        maps[a][b] = true; maps[b][a] = true; 
    }
}

void visted_inital(){
    for(bool &n : visted)
        n = false;
}

void dfs(int x, int &n){
    visted[x] = true;

    for(int i = 1 ; i < 101; i++){
        if(maps[x][i] == true && !visted[i]){
            n++;
            dfs(i, n);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    draw_maps(wires);

    //dfs로 한 전력망이 결합된 갯수를 구한다. 구한 값이 r개 이면 다른 전력망은 n-r이다.
    //따라서 두 사이값 차는 n-2r이다.

    //하나의 전력망을 하나하나씩 잘라본다.
    for(auto &v : wires){

        int a = v[0], b = v[1];
        maps[a][b] = false; maps[b][a] = false;
        
        int count = 1;
        dfs(1,count);
        answer = min(answer, abs(n-2*count));

        //원래대로 만들기
        visted_inital(); 
        maps[a][b] = true; maps[b][a] = true;
    }
    
    return answer;
}

int main(){
    solution(9, {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}});
}