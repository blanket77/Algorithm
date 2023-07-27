#include <string>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;

    int back_num = 0;
    int current_num = 0;
    for(int n = 0 ; n < dartResult.size(); n++){
        char i = dartResult[n];
        if(i == '1' && dartResult[n+1] == '0'){
            back_num = current_num;
            current_num = 10;
            n++;
            continue;
        }
        else if('0' <= i && i <= '9'){
            back_num = current_num;
            current_num = i-'0';
        }
        else if(i == 'S'){
            answer += current_num;
        }
        else if(i == 'D'){
            current_num = pow(current_num,2);
            answer += current_num;
        }
        else if(i == 'T'){
            current_num = pow(current_num,3);
            answer += current_num;
        }
        else if(i == '*'){
            answer += current_num + back_num;
            current_num *= 2;
            back_num *= 2;
        }     
        else if(i == '#'){
            answer -= 2*current_num;
            current_num *= -1;
        }
    }

    return answer;
}

int main(){
    string s = "1D2S0T";
    solution(s);
}