#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    while(n != 0){
        int qt = n/3;
        int rm = n%3;
        if(rm == 0){
            qt--; 
            rm += 4;
        }
        answer += to_string(rm);
        n = qt;
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}