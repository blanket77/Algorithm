#include <string>
#include <vector>

using namespace std;

void hanoi(int num, int from, int to, int other, vector<vector<int>> &a){
    if(num == 0) return;

    hanoi(num-1, from, other, to, a);
    vector<int> v = {from,to};
    a.push_back(v);
    hanoi(num-1, other, to, from, a);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    hanoi(n,1,3,2, answer);

    return answer;
}