#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string s, char c){
    vector<string> answer;
    string temp;
    stringstream ss(s);
    
    while(getline(ss, temp, c)){
        if(temp != "")
            answer.push_back(temp);
    }
    return answer;
}

vector<string> solution(string myString) {
    vector<string> answer = split(myString, 'x');
    sort(answer.begin(), answer.end());
    return answer;
}