#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    for(int i = 0; i < number.size(); i++){
        for(int j = 0; j < number.size(); j++){
            for(int m = 0; m < number.size(); m++){
                if(i == j || i == m || j == m)
                    continue;
                if(number[i] + number[j] + number[m] == 0){
                    answer++;
                }
            }
        }
    }
    return answer/6;
}