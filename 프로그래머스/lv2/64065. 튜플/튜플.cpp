#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b){
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> m;
    string temp;
    
    while(s.find("{") != string::npos)
        s.replace(s.find("{"), 1, "");
    while(s.find("}") != string::npos)
        s.replace(s.find("}"), 1, "");
    
    stringstream ss(s);
    while(getline(ss, temp, ','))
        m[stoi(temp)]++;
    
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    
    for(auto it = v.begin(); it != v.end(); it++)
        answer.push_back(it->first);
    
    return answer;
}