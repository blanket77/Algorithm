#include <string>
#include <vector>
#define MAX_N 100000+1

using namespace std;

int solution(int n) {
    int answer = 0;

    int arr[MAX_N];
    int divide = 1234567;
    arr[0] = 0;
    arr[1] = 1;

    

    for(int i = 2 ; i < MAX_N ; i++){
        arr[i] = arr[i-1]%divide + arr[i-2]%divide;
        arr[i] %= divide;
    }

    answer = arr[n]%divide;


    return answer;
}