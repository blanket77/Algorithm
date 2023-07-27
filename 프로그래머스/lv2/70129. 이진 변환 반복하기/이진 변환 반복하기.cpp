#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2,0);

    
    while(s != "1"){
        int zero_count = 0;

        for(int i = 0 ; i < s.length() ; i++){
            char c = s[i];
            if(c == '0'){
                zero_count++;
                s.erase(s.begin()+i);
                i--;
            }
        }

        int n = s.length();
        s = "";

        while(n != 0){
            s += to_string(n%2);
            n /= 2;
        }

        answer[0]++;
        answer[1] += zero_count;
    }

    return answer;
}