#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    while(n >= 2){
        n -= 2;
        answer += "수박";
    }
    if(n == 1)
        answer += "수";
    return answer;
}