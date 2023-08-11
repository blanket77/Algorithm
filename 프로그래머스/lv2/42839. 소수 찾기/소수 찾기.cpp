#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath> 
#define MAX_N 10000000

using namespace std;

vector<bool> isPrime(MAX_N,true);
// 에라토스테네스의 체
void prime(){
    isPrime[0] = false; isPrime[1] = false;
    

    for(int i = 2; i < sqrt(MAX_N); i++){
        for(int j = i * i; j < 10000001; j += i){
            isPrime[j] = false; 
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    vector<bool> visited(MAX_N, false);
    prime(); // 소수 체크
    
    sort(numbers.begin(), numbers.end()); //내림차순 후 next_permutation
    do{
        for(int i = 1 ; i <= numbers.length(); i++){
            int num = stoi(numbers.substr(0,i));

            if(!visited[num] && isPrime[num]){
                answer++;
                visited[num] = true;
            }
        }
    }
    while(next_permutation(numbers.begin(), numbers.end()));


    return answer;
}

int main(){
    solution("123");
}