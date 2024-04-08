#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    int before_idx = 0;
    for(int i = 0; i < myString.size(); i++){
        if(myString[i] == 'x'){
            answer.push_back(i - before_idx);
            before_idx = i + 1;
        }
    }
    answer.push_back(myString.size() - before_idx);
    return answer;
}