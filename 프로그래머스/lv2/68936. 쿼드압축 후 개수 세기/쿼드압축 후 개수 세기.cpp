#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int zero = 0, one = 0;
    
    for(auto ar : arr){
        for(auto a : ar){
            if(a == 1)
                one++;
            else
                zero++;
        }
    }
    
    for(int i = 2; i <= arr.size(); i *= 2){
        for(int m = 0; m <= arr.size()-2; m += i){
            for(int n = 0; n <= arr.size()-2; n += i){
                int cnt = 0;
                int num = arr[m][n];
                for(int x = 0; x < i; x++){
                    for(int y = 0; y < i; y++){
                        if(num == arr[m+x][n+y]){
                            cnt++;
                        }
                    }
                }
                if(cnt == i*i){
                    if(num == 0)
                        zero -= 3;
                    else
                        one -= 3;
                }
            }
        }
    }
    answer.push_back(zero);
    answer.push_back(one);
    
    return answer;
}