#include <string>
#include <vector>
#include <algorithm>

bool compare(int i, int j){
    return i > j;
}

using namespace std;

string solution(string s) {
    string answer = s;
    
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}