#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";

    map<char, bool> m;
    for(auto c : skip){
        m[c] = true;
    }

    int diff = 'z' - 'a' +1;
    for(auto c : s){
        for(int i = 0 ; i < index; i++){
            c++;
            if(c > 'z')  c -= diff; 
            
            while(m.find(c) != m.end()){
                c++; 
                if(c > 'z')  c -= diff; 
            }
        }
        answer += c;
    }


    return answer;
}