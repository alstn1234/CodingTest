#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int i, int j){
    string ii = to_string(i);
    string jj = to_string(j);
    
    string sum = ii + jj;
    string sum2 = jj + ii;
    
    if(stoi(sum) > stoi(sum2))
        return true;
    else
        return false;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);
    for(auto num : numbers){
        string s = to_string(num);
        answer += s;
    }
    while(answer.length() != 1 && answer[0] == '0')
        answer.erase(0,1);
    
    return answer;
}