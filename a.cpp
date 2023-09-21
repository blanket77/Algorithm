#include<iostream>

using namespace std;

bool problem[256] = {false,};

bool solve(int a, int b){
    for(int i = a ; i <= b; i++){
        problem[i] = true;
    }
}

int main(){
    int objective = 105;

    solve(1,37);
    solve(42,43);
    solve(86,98);
    solve(149,150);
    solve(205,239);
    solve(247,255);

    int circle =0;
    for(auto a : problem){
        if(a)
            circle++;
    }

    cout << "목표 : " << objective << endl;
    cout << "푼 갯수 : " << circle << endl;
    cout << "성취률 : " << ((double)circle/objective*100) << "%" << endl;
}