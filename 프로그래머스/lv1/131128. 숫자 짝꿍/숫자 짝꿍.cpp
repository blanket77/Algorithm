#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(char a, char b){
    return a > b;
}

string solution(string X, string Y) {
    string A = "";

    int n_X[10] = {0,}; int n_Y[10] = {0,};
    for(auto c : X)
        n_X[c - '0']++;
    
    for(auto c : Y)
        n_Y[c - '0']++;
    
    for(int i = 9 ; i >= 0 ; i--){
        if(n_X[i] > n_Y[i])
            A.append(n_Y[i], i + '0');
        else
            A.append(n_X[i], i + '0');
    }
    if(A.empty())
        A = "-1";
    
    if(!A.empty() && A[0] == '0'){
        A = "0";
    }
    

    string answer = A;

    return answer;
}
