#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char c){
    vector<string> answer;
    stringstream ss(input);
    string temp;
    
    while(getline(ss, temp, c))
        answer.push_back(temp);
    return answer;
}

int solution(string s) {
    int answer = 0;
    vector<string> v = split(s, ' ');
    while(!v.empty()){
        if(v.back() == "Z"){
            v.pop_back();
            v.pop_back();
        }else{
            answer += stoi(v.back());
            v.pop_back();
        }
    }
    return answer;
}