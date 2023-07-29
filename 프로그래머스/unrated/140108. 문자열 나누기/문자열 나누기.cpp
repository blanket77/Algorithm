#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    char first = s[0];
    int count_first = 0;
    int count_other = 0;

    for(int i = 0; i < s.size(); i++){
        char c= s[i];
        if(count_first == 0)
            first = s[i];

        if(c == first) count_first++;
        else count_other++;

        if(count_first == count_other){
            answer++;
            count_first = 0;
            count_other = 0;

            if(i+1 < s.size())
                first = s[i+1];
            continue;
        }
        if(count_first != count_other && i+1 >= s.size())
            answer++;
    }

    return answer;
}