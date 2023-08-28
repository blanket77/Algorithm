#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    string tmp[3] = {"4","1","2"};

    while(n != 0){
        int index = n%3;
        answer += tmp[index];
        n /= 3;

        if(index == 0)
            n--;
    }

    reverse(answer.begin(), answer.end());

    return answer;
}