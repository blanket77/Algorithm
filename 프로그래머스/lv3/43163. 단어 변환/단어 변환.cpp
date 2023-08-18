#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

int answer = INT_MAX;
int len;

int same_char(const string &a, const string &b){
    int count = 0;
    for(int i = 0 ; i < a.length(); i++){
        if(a[i] == b[i]) count++;
    }
    return count;
}

void dfs(int count, const string &b, const string &t, const vector<string>& w, vector<string>& v){
    if(b == t){
        answer = min(answer, count);
        return;
    }
    
    for(int i = 0; i < w.size(); i++){
        if(find(v.begin(), v.end(), w[i]) != v.end()) // 이미 쓴 단어다.
            continue;
        if(len -1 == same_char(b, w[i])){ //기존 단어랑 알파벳이 다른게 하나라면 dfs
            v.push_back(w[i]);
            dfs(count+1,w[i],t,w,v);
            v.pop_back();
        }
    }
}


int solution(string begin, string target, vector<string> words) {
    len = begin.length();
    vector<string> visted;

    if(find(words.begin(), words.end(), target) == words.end())
        return 0;

    dfs(0, begin, target, words, visted);

    if(answer == INT_MAX)  // 변환 불가능
        return 0;

    return answer;
}

int main(){
    solution("hit","cog",{"hot", "dot", "dog", "lot", "log", "cog"});
}