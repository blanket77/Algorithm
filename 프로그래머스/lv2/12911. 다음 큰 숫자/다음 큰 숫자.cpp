#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    int Ing_n = n;
    int cur_1_num = 0;
    while(n){
        if(n % 2 == 1)
            cur_1_num++;
        n /= 2;
    }

    int ing_1_num = 0;
    while(cur_1_num != ing_1_num){
        ing_1_num = 0;
        int num = ++Ing_n;
        while(num){
            if(num % 2 == 1)
                ing_1_num++;
            num /= 2;
        }    
    }
    answer = Ing_n;

    return answer;
}
