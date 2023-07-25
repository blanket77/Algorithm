#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double, int> a, pair<double, int> b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<int> s(N + 2,0); // index 0 무시, N+1까지 선언

    for(auto i : stages)
        s[i]++;  

    vector <pair<double, int>> m;
    int pn = stages.size();

    for(int i = 1 ; i <= N; i++){
        if(pn == 0) {m.push_back({0,i}); continue;}
        
        double n = (double)s[i]/pn;
        
        m.push_back({n,i});
        pn -= s[i];
    }

    sort(m.begin(), m.end(), compare);
    for(auto i : m){
        answer.push_back(i.second);
    }

    return answer;
}