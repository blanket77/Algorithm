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

        if(n == s.size()-1 )
            num.push_back(stoi(a));
    }

    sort(num.begin(), num.end());
    
    answer += to_string(num.front()) + " ";
    answer += to_string(num.back());

    return answer;
}