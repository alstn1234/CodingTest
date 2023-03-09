#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    int n = 1;
    for(char i = 'A'; i <= 'Z'; i++){
        string s = ""; s += i;
        m[s] = n++;
    }
    int idx = 0;
    while(idx != msg.length()){
        string before_s = ""; before_s += msg[idx];
        string next_s = before_s + msg[idx+1];
        
        while(m.find(next_s) != m.end()){
            before_s = next_s;
            next_s = before_s + msg[++idx+1];
        }
        
        m[next_s] = n++;
        answer.push_back(m[before_s]);
        idx++;
    }
    
    return answer;
}