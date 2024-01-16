#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    vector<int> a = topping;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(),a.end()),a.end());      

    int young = a.size();
    int old = 0;

    int num[10001] = {0, };
    bool b_num[10001] = {false,};

    for(int n : topping){
        num[n]++;
    }


    for(int i = 0 ; i < topping.size(); i++){
        int t_name = topping[i];
        
        if(!b_num[t_name]){
            b_num[t_name] = true;
            old++;
        }
        num[t_name]--;
        if(num[t_name] == 0)
            young--;
        
        if(young == old)
            answer++;
    }


    return answer;
}

int main(){
    solution({1, 1, 4, 7, 7, 5});
}