#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> split(string input, char del){
    vector<int> answer;
    stringstream ss(input);
    string temp;
    
    while(getline(ss, temp, del)){
        answer.push_back(stoi(temp));
    }
    return answer;
}

string solution(string s) {
    string answer = "";
    vector<int> v = split(s, ' ');
    sort(v.begin(), v.end());
    answer += to_string(v.front()) + " " + to_string(v.back());
    return answer;
}