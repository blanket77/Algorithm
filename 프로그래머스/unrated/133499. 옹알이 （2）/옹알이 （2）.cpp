#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> two_word = {"ye","ma"};
    vector<string> three_word = {"aya","woo"};

    for(auto s : babbling){
        string back_word = "";
        int idx = 0;
        while(true){
            int current = idx;
            for(auto t : two_word){
                string tw = s.substr(idx,2);
                if(tw == t && tw != back_word){
                    back_word = t;
                    idx += 2;        
                }
            }
            for(auto t : three_word){
                string tw = s.substr(idx,3);
                if(tw == t && tw != back_word){
                    back_word = t;
                    idx += 3;        
                }
            }
            if(current == idx)
                break;
            if(idx == s.length()) {
                answer++; 
                break;
            }
        }
        
    }
     
    return answer;
}