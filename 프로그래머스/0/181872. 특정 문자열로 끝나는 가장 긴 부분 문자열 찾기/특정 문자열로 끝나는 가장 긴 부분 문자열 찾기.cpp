#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string myString, string pat) {
    string answer = "";
    reverse(myString.begin(), myString.end());
    reverse(pat.begin(), pat.end());
    answer = myString.substr(myString.find(pat));
    reverse(answer.begin(), answer.end());
    return answer;
}