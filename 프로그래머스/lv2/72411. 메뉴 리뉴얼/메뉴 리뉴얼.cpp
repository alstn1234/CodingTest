#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> v(11, 0);
map<string, int> m;

void dfs(string order, int req, string s){
    if(s.length() == req){
        sort(s.begin(), s.end());
        m[s]++;
        v[req] = max(v[req], m[s]);
        return;
    }
    if(order.size() == 0)
        return;
    for(int i = 0; i < order.size(); i++){
        string cp_order = order;
        cp_order.erase(0, i+1);
        dfs(cp_order, req, s+order[i]);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(auto order : orders){
        for(auto req : course){
            if(req > order.length())
                break;
            dfs(order, req, "");
        }
    }
    for(auto req : course){
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->first.length() == req && it->second == v[req] && it->second >= 2){
                answer.push_back(it->first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}