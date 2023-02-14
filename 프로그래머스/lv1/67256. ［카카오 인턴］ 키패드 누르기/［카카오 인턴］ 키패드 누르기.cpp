#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int right = 10, left = 12;
    for(auto num : numbers){
        if(num == 0)
            num = 11;
        
        if(num == 1 || num == 4 || num == 7){
             left = num;
            answer += 'L';
            continue;
        }
        if(num == 3 || num == 6 || num == 9){
             right = num;
            answer += 'R';
            continue;
        }
        
        int r = abs(num-right)/3 + abs(num-right)%3;
        int l = abs(num-left)/3 + abs(num-left)%3;
        if(r < l){
            right = num;
            answer += 'R';
        }
        else if(r > l){
            left = num;
            answer += 'L';
        }
        else{
            if(hand == "right"){
                right = num;
                answer += 'R';
            }
            else{
                left = num;
                answer += 'L';
            }
        }
    }
    return answer;
}