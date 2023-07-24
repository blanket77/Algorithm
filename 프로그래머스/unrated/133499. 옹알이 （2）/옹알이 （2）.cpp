#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> word = {"ye","ma","aya","woo"};

    for(auto s : babbling){
        string back_word = "";
        int idx = 0;
        while(true){
            int current = idx;
            for(auto t : word){
                int t_len = t.length(); // 말할 수 있는 단어
                string tw = s.substr(idx, t_len);
                if(tw == t && tw != back_word){
                    back_word = t;   //  중복한 것은 배제
                    idx += t_len;    //  말할 수 있는 단어 길이 만큼 sum    
                }
            }

            if(current == idx)  // 변화가 없다는 것은 말할 수 있는 단어가 없다는 뜻
                break;
            if(idx == s.length()) {
                answer++; 
                break;
            }
        }
        
    }
     
    return answer;
}