#include <string>
#include <vector>

using namespace std;
using ULL = unsigned long long;

int solution(string t, string p) {
    int answer = 0;
    int p_l = p.length();
    ULL pp = stoull(p);

    for(int i = 0 ; i < t.size() - p_l +1; i++){
        string cut_t = t.substr(i, p_l);
        if(pp >= stoull(cut_t))
            answer++;
    }

    return answer;
}