#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    long long num = 0;
    sort(weights.rbegin(), weights.rend());
    
    for(int i = 0; i < weights.size() - 1; i++){
        if(num > 0 && (weights[i] == weights[i-1])){
            num--;
            answer += num;
            continue;
        }
        num = 0;
        for(int j = i + 1; j < weights.size(); j++){
            double w = (double)weights[i] / (double)weights[j];
            if(w == 1 || w == 3.0/2.0 || w == 4.0/3.0 || w== 2) num++;
        }
        answer += num;
    }
    return answer;
}