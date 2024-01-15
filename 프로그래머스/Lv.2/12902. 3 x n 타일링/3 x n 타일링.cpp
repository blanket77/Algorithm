#include <string>
#include <vector>
#define MODULER 1000000007

using namespace std;

int solution(int n) {
    long long dp[5001] = {0,};
    dp[2]= 3;
    
    for(int i = 4 ; i <= n ; i+=2){
        dp[i] = (dp[i-2]*3+2);
        
        for(int j = i-4 ; j >= 0 ; j-=2 ){
            dp[i] += (dp[j]*2);
        }
        dp[i] = dp[i] % MODULER;
    }
    
    return dp[n];
}