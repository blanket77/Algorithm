#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    string answer_str;

    map<string, char> n;
    n["one"] = '1'; n["two"] = '2'; n["three"] = '3'; n["four"] = '4'; n["five"] = '5';
    n["six"] = '6'; n["seven"] = '7'; n["eight"] = '8'; n["nine"] = '9'; n["zero"] = '0';

    string num = "";
    
    for(auto c : s){
        if('0' <= c && c <= '9'){
            answer_str += c;
        }
        else
            num += c;

        if(n.find(num) != n.end()){
            answer_str += n[num];
            num = "";
        }

    }

    answer = stoi(answer_str);
    
    return answer;
}