#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for (int i = 0; i < quiz.size(); i++) {
        vector<string> v = split(quiz[i], ' ');
        if (v[1] == "-") {
            if (stoi(v[0]) - stoi(v[2]) == stoi(v[4]))
                answer.push_back("O");
            else
                answer.push_back("X");
        }
        if (v[1] == "+") {
            if (stoi(v[0]) + stoi(v[2]) == stoi(v[4]))
                answer.push_back("O");
            else
                answer.push_back("X");
        }
    }
    return answer;
}
