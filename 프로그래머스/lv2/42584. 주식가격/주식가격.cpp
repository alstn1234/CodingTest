#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i = 0; i < prices.size()-1; i++){
        answer.push_back(0);
        for(int j = 1 + i ; j < prices.size(); j++){
            if(prices[i] <= prices[j])
                answer[i]++;
            else{
                answer[i]++;
                break;
            }
        }
    }
    answer.push_back(0);
    return answer;
}