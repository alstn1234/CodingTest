#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> split(string s, char c){
    vector<string> answer;
    stringstream ss(s);
    string temp;
    
    while(getline(ss, temp, c)){
        answer.push_back(temp);
    }
    
    return answer;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    vector<vector<string>> v;
    
    for(auto r : record){
        vector<string> vs = split(r, ' ');
        if(vs[0] != "Change")
            v.push_back(vs);
        if(vs[0] != "Leave")
            m[vs[1]] = vs[2];
    }
    
    for(auto e : v){
        string s = m[e[1]];
        if(e[0] == "Enter")
            s += "님이 들어왔습니다.";
        if(e[0] == "Leave")
            s += "님이 나갔습니다.";
        answer.push_back(s);
    }
    return answer;
}