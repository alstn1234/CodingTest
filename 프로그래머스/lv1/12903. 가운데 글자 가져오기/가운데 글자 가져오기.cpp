#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int size = s.length();
    answer = (size%2==0) ? answer+s[size/2-1]+s[size/2] : answer+s[size/2];
    return answer;
}