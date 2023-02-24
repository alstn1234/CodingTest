#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    vector<string> v = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };
    for(int i = 0; i < v.size(); i++){
        string ss = to_string(i);
        while(s.find(v[i]) != string::npos)
            s.replace(s.find(v[i]), v[i].length(), ss);
    }
    return stoi(s);
}