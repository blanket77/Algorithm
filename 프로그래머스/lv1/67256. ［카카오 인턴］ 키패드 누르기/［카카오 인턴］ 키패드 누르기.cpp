#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int current_lh = 10; //*
    int current_rh = 12; //#

    for(auto n : numbers){
        if(n == 0){
            n = 11;
        }

        if(n == 1 || n == 4 || n == 7){
            answer += "L";
            current_lh = n;
        }
        else if(n == 3 || n == 6 || n == 9){
            answer += "R";
            current_rh = n;
        }
        else{
            int tmp_l, tmp_r;
            bool ls = false, rs = false; 
            if(current_lh == 2 || current_lh == 5 || current_lh == 8 || current_lh == 11)
                tmp_l = current_lh;
            else{
                tmp_l = current_lh + 1;
                ls = true;
            }

            if(current_rh == 2 || current_rh == 5 || current_rh == 8 || current_rh == 11)
                tmp_r = current_rh;
            else{
                tmp_r = current_rh - 1;
                rs = true;
            }

            tmp_l = abs(n - tmp_l);
            tmp_r = abs(n - tmp_r);
            if(ls) tmp_l += 3;
            if(rs) tmp_r += 3;

            if(tmp_l < tmp_r){
                answer += "L";
                current_lh = n;
            }
            else if(tmp_l > tmp_r){
                answer += "R";
                current_rh = n;
            }
            else{
                if(hand == "left"){
                    answer += "L";
                    current_lh = n;
                }
                else{
                    answer += "R";
                    current_rh = n;
                }
            }
        }
    }


    return answer;
}

int main(){
    solution({1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5}, "right");
}