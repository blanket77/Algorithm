#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int count = 0;
    while(k != count){
        bool check = true;
        for(int i = 0 ; i < number.length() - 1 ;i++){
            if(number[i] < number[i+1]){
                number.erase(i,1);
                count++; check = false;
                break;
            }
        }
        //지울게 없으면 마지막 숫자를 지운다.
        if(check){
            number.erase(number.length()-1,1);
            count++;
        }
    }

    answer = number;

    return answer;
}

int main(){
    solution("4321",1);
}