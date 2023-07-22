#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    map<string, int> n_y;
    
    for(int i = 0 ; i < name.size(); i++)
        n_y[name[i]] = yearning[i];
    
    for(auto i : photo){
        int sum = 0;
        for(auto name : i){
            sum += n_y[name];
        }
        answer.push_back(sum);
    }
    
    return answer;
}