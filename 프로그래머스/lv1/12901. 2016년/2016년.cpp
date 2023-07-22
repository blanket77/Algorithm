#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(int a, int b) {
    string answer = "";
                    //   0   1   2  3   4   5   6    7   8   9   10   11   12
    int month_day[13] = {0, 31, 29, 31, 30, 31, 30 , 31, 31, 30,  31,  30 , 31  };

    map<int, string> days;
    days[1] = "FRI"; days[2] = "SAT"; days[3] = "SUN"; days[4] = "MON";
    days[5] = "TUE"; days[6] = "WED"; days[0] = "THU";    

    int total_day = 0;
    for(int i = 1 ; i < a ; i++){
        total_day += month_day[i];
    }
    total_day += b;

    answer += days[total_day%7];

    return answer;
}