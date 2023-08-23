#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    int r = arr1.size();
    int c = arr2[0].size();

    for(int i = 0 ; i < r; i++){
        vector<int> v;
        for(int j = 0 ; j < c ; j++){
            int tmp = 0;
            for(int n = 0 ; n < arr1[0].size(); n++)
                tmp += arr1[i][n] * arr2[n][j];
            
            v.push_back(tmp);
        }
        answer.push_back(v);
    }

    return answer;
}