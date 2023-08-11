#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> tmp;
    for(auto n : numbers)
        tmp.push_back(to_string(n));
    

    sort(tmp.begin(), tmp.end(), compare);
    
    for(auto s : tmp)
        answer += s;

    if(answer[0] == '0') return "0";

    return answer;
}
