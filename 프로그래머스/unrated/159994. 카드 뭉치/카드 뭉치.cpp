#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";

    bool possible = true;
    int s1 = 0;
    int s2 = 0;

    for(auto str : goal){
        if(cards1[s1] == str)
            s1++;
        else if(cards2[s2] == str)
            s2++;
        else
            possible = false;
    }

    if(possible)
        answer += "Yes";
    else
        answer += "No";

    return answer;
}