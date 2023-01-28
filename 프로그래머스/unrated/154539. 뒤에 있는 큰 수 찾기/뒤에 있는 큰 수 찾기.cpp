#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int max_value = numbers[numbers.size() - 1];
    for(int i = numbers.size() - 2; i >= 0; i--){
        if(max_value < numbers[i + 1]){
            numbers.erase(numbers.begin() + i + 2, numbers.end());
            max_value = numbers[i + 1];
        }
        if(numbers[i] >= max_value){
            answer.push_back(-1);
            continue;
        }
        for(int j = i + 1; j < numbers.size(); numbers.erase(numbers.begin() + j)){
            if(numbers[i] < numbers[j]){
                answer.push_back(numbers[j]);
                break;
            }
        }
    }
    reverse(answer.begin(), answer.end());
    answer.push_back(-1);
    return answer;
}