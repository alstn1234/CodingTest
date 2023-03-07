#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
    string answer = "";
    for(const auto r : rsp){
        if(r == '2')
            answer += '0';
        else if(r == '5')
            answer += '2';
        else if(r == '0')
            answer += '5';
    }
    return answer;
}