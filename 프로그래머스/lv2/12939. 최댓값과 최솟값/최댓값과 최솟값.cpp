#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> num;

    string a = "";

    for(int n = 0 ; n < s.size(); n++){
        char c = s[n];
        
        if(c == ' '){
            num.push_back(stoi(a));
            a = "";
        }
        else
            a += c;
    }
    num.push_back(stoi(a)); // 마지막 숫자를 등록
        
    sort(num.begin(), num.end());
    
    answer += to_string(num.front()) + " ";
    answer += to_string(num.back());

    return answer;
}