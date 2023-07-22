#include <string>
#include <vector>

using namespace std;


int solution(vector<int> ingredient) {
    int answer = 0;
    string str = "";

    for(auto n : ingredient){
        str += to_string(n);
        int len = str.length();
        if(len >= 4){
            int inx = len - 4;
            if(str.substr(inx) == "1231"){
                str = str.substr(0, inx);
                answer++;
            }
        }
    }

    return answer;
}