    #include <string>
    #include <vector>
    #include <queue>

    using namespace std;

    void init_q(queue<pair<int,int>>& qq, vector<int>& t){
        for(int i = 0 ; i < t.size(); i++){
            qq.push({t[i],0});
        }
    }

    int weightSumBrige(queue<pair<int, int>> q){
        int sum = 0;

        while(!q.empty()){
            sum += q.front().first;
            q.pop();
        }

        return sum;
    }

    int timePlus(queue<pair<int,int>>& q, int const n){
        int c = 0;

        int len = q.size();
        for(int i = 0 ; i < len ; i++){
            if(q.front().second + 1 == n){
                q.pop();
                c++;
            }
            else{
                q.front().second++;
                q.push(q.front());
                q.pop();
            }
        }

        return c;
    }


    int solution(int bridge_length, int weight, vector<int> truck_weights) {
        int times = 0;
        queue<pair<int, int>> q;
        init_q(q, truck_weights);
        
        queue<pair<int, int>> w_on_b;

        int count = 0;
        int truck_num = truck_weights.size();
        
        while(count != truck_num){
            times++;

            int front_tw = q.front().first;
            if( (weight >= weightSumBrige(w_on_b) + front_tw) && !q.empty()){
                //q.front().second++;
                w_on_b.push(q.front());
                q.pop();
            }
            count += timePlus(w_on_b, bridge_length);
            
        }

        return times+1;
    }

    int main(){
        solution(	2, 10, {7, 4, 5, 6});
        return 0;
    }