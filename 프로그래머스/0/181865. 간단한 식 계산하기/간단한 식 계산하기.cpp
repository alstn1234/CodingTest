#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string s, char del){
    vector<string> answer;
    string stringBuffer;
    stringstream ss(s);
    
    while(ss >> stringBuffer)
        answer.push_back(stringBuffer);
    return answer;
}

int solution(string binomial) {
    int answer = 0;
    vector<string> bin = split(binomial, ' ');
    int num1 = stoi(bin[0]), num2 = stoi(bin[2]);
    if(bin[1] == "+")
        answer = num1 + num2;
    if(bin[1] == "-")
        answer = num1 - num2;
    if(bin[1] == "*")
        answer = num1 * num2;
    return answer;
}