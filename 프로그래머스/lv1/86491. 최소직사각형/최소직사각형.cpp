#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//가장 긴 길이와 

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int hight = 0;
    int weight = 0;

    for(int i = 0 ; i < sizes.size(); i++){
        if(sizes[i][0] < sizes[i][1]){
            weight = max(sizes[i][1], weight);
            hight = max(sizes[i][0], hight);
        }

        else{
            weight = max(sizes[i][0], weight);
            hight = max(sizes[i][1], hight);
        }
    }

    answer = weight * hight;

    return answer;
}