#include <vector>
#include <iostream>
#define MAX_NUM 3001
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    vector<bool> isPrime(MAX_NUM , true);
    isPrime[1] = false;

    for(int i = 2 ; i < MAX_NUM ; i++){
        for(int j = 2 ; i * j < MAX_NUM; j++){
            isPrime[i*j] = false;
        }
    }

    for(int i = 0 ; i < nums.size() ; i++){
        for(int j = i+1 ; j < nums.size() ; j++){
            for(int k = j+1 ; k < nums.size() ; k++){
                if(isPrime[nums[i] + nums[j] + nums[k]])
                    answer++;
            }
        }
    }
    return answer;
}