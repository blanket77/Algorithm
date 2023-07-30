#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> n;
    vector<vector<int>> m;

    // board 0 값 제거
    for(int i = 0 ; i < board.size();i++){
        for(int j = 0 ; j < board.size(); j++){
            if(board[j][i] != 0)
                n.push_back(board[j][i]);
        }
        m.push_back(n);
        n.clear();
    }

    vector<int> box;

    for(auto i : moves){
        int index = i-1;
        if(!m[index].empty()){
            if(!box.empty() && box.back() == m[index].front()){
                answer += 2;
                box.pop_back();
            }
            else{
                box.push_back(m[index].front());
            }
            m[index].erase(m[index].begin());
        }
    } 

    return answer;
}

int main(){
    vector<int> v1 = 	{0, 0, 0, 0, 0};
    vector<int> v2 = {0, 0, 1, 0, 3};
    vector<int> v3 = {0, 2, 5, 0, 1};
    vector<int> v4 = {4, 2, 4, 4, 2};
    vector<int> v5 = {3, 5, 1, 3, 1};

    vector<vector<int>> v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);

    solution(v, {1,5,3,5,1,2,1,4});
}

