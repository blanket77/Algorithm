#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int t[600001];
    
    t[1] = 1;
    t[2] = 2;

    for(int i = 3 ; i <= n ; i++){
        t[i] = (t[i-1] + t[i-2])% 1000000007;
    }

    answer = t[n] ;

    return answer;
}