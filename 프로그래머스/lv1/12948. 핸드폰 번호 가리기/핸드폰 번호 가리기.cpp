#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";

    answer += phone_number;
    for(int i = 5 ; i <= answer.length() ; i++){
        answer[answer.length()-i] = '*';
    }

    return answer;
}