#include <string>
#include <vector>
#include <iostream>

using namespace std;

string to_n_ary(int num, int b){
    string str = "";
    while(num > 0){
        int a = num%b;
        if(a < 10)
            str = to_string(a)+str;
        else
            str = (char)('A'+a-10)+str;
        
        num /= b;
    }
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string game_word = "0";
    
    int cur = 0; 
    //create game_word as many as needed
    while(game_word.length() < t*m){
        game_word += to_n_ary(cur, n);
        cur++;
    }
    
    //in game_word, print answer
    int cnt = 0;
    for(int i = p-1 ; i < t*m ; i += m){
        answer += game_word[i];
        if(++cnt == t)
            break;
    }
    
    return answer;
}

int main(){
    cout << solution(2,4,2,1);
}