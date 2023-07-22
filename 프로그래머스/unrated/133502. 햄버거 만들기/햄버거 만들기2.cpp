#include <string>
#include <vector>

using namespace std;


int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> cook = {-1};

    for(auto n : ingredient){
        int cook_bf = cook.back(); 

        if(cook_bf == 1 && n == 2) cook.back() = 12;
        else if(cook_bf == 12 && n == 3) cook.back() = 123;
        else if(cook_bf == 123 && n == 1) {cook.pop_back(); answer++;}
        else cook.push_back(n);
    }

    return answer;
}