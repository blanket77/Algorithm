#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string ten_min_plus(string s){
    if(s[3] == '5'){
        s[3] = '0';
        if(s[1] != '9')
            s[1] += 1;
        else{
            s[1] = '0';
            s[0] += 1;
        }
    }
    else
        s[3] += 1;

    return s;
} 

// s1이 같거나 크면 true를 반환
bool compare_time(const string &s1, const string &s2){
    for(int i = 0; i < 5; i++){
        if(i == 2) continue;
        if(s1[i] > s2[i])
            return true;
        else if(s1[i] < s2[i])
            return false;        
    }
    // 다 같다
    return true;
}

int solution(vector<vector<string>> book_time) {
    vector<vector<string>> room;
    sort(book_time.begin(), book_time.end());
    
    for(const auto &t : book_time){
        
        string start_time = t[0];
        bool check = false; 
         
        for(auto &r : room){
            string end_time = r[1];
            //시작 시간이 끝난 시간과 같거나 크면 방에 들어갈 수 있다.
            if(compare_time(start_time, end_time)){
                r[0] = t[0];
                r[1] = ten_min_plus(t[1]); 
                check = true;
                break;
            }
        }
        if(!check)
            room.push_back({t[0], ten_min_plus(t[1])});
    }
    int answer = room.size();
    return answer;
}

int main(){
    //compare_time("15:00", "15:20");
    solution({{"15:00", "17:00"}, {"16:40", "18:20"}, {"14:20", "15:20"}, {"14:10", "19:20"}, {"18:20", "21:20"}});
    return 0;
}