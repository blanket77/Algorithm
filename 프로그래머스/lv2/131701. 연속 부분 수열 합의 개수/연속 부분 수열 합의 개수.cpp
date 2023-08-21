#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> s;

void sumsum(int len, const vector<int> &elements){
    for(int i = 0 ; i < elements.size(); i++){
        int sum = 0;
        for(int j = i ; j < len+i ; j++){
            if(j >= elements.size())
                sum += elements[j - elements.size()];
            else
                sum += elements[j];
        }
        s.insert(sum);
    }
}

int solution(vector<int> elements) {
    int answer = 0;

    int len = 1;

    while(elements.size() >= len){
        sumsum(len, elements);
        len++;
    }

    answer = s.size();

    return answer;
}