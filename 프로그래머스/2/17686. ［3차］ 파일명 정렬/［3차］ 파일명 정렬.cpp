#include <string>
#include <vector>
#include <algorithm>

using namespace std;


struct fileName
{
    int idx;
    string head;
    int number;
};

bool cmp(const fileName &f1, const fileName &f2){
    if(f1.head == f2.head){
        if(f1.number == f2.number)
            return f1.idx < f2.idx;

        return f1.number < f2.number;
    }

    return f1.head < f2.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    vector<fileName> v;
    
    for(int i = 0 ; i < files.size(); i++){
        string numnum ="";
        string head ="";
        bool check = false;

        for(int j = 0; j < files[i].length(); j++){
            if('0' <= files[i][j] && '9' >= files[i][j]){
                numnum = numnum + files[i][j];
                check = true;
            }
            else{
                if(check) break;
                else head = head + files[i][j];
            }
        }

        for(int i = 0 ; i < head.length() ; i++ )
            head[i] = tolower(head[i]);
        
        int number = stoi(numnum);
        
        fileName f;
        f.idx = i;
        f.head = head;
        f.number = number;
        
        v.push_back(f);
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i = 0 ; i < v.size(); i++){
        answer.push_back(files[v[i].idx]);
    }

    return answer;
}
