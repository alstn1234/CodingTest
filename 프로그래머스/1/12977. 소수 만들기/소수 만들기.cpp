#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool IsDecimal(int num){
    if(num%2 == 0)
        return false;
    for(int i = 3; i <= sqrt(num); i+=2)
        if(num%i == 0)
            return false;
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    for(int i = 0; i < nums.size() - 2; i++){
        for(int j = i + 1; j < nums.size() - 1; j++){
            for(int m = j + 1; m < nums.size(); m++){
                if(IsDecimal(nums[i] + nums[j] + nums[m])){
                    answer++;
                }
            }
        }
    }

    return answer;
}