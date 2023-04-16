#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.rbegin(), targets.rend());
    while(!targets.empty()){
        int target_e = targets.back()[1];
        targets.pop_back();
        while(!targets.empty() && target_e > targets.back()[0]){
            if(target_e > targets.back()[1])
                target_e = targets.back()[1];
            targets.pop_back();
        }
        answer++;
    }
    return answer;
}