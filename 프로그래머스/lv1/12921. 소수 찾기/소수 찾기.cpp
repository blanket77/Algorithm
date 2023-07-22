#include <string>
#include <vector>
#define MAX_N 1000001

using namespace std;

int solution(int n) {
    int answer = 0;

    vector<bool> isPrime(MAX_N, true);
    isPrime[1] = false;

    for(int i = 2 ; i < isPrime.size(); i++){
        for(int j = i+i ; j < isPrime.size() ; j += i){
            isPrime[j] = false;
        }
    }

    for(int i = 1 ; i <= n; i++){
        if(isPrime[i])
            answer++;
    }

    return answer;
}