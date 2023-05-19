#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

vector<vector<char>> pri;

void dfs(vector<char> v, vector<char> p){
    if(v.empty()){
        pri.push_back(p);
        return;
    }
    
    for(int i = 0; i < v.size(); i++){
        vector<char> vec(v);
        p.push_back(vec[i]);
        vec.erase(vec.begin()+i);
        dfs(vec, p);
        p.pop_back();
    }
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> con;
    vector<char> oper;
    
    string s = "";
    for(auto ex : expression){
        if(ex == '-' || ex == '+' || ex == '*'){
            con.push_back(stoi(s));
            s = "";
            oper.push_back(ex);
        }
        else
            s += ex;
    }
    con.push_back(stoi(s));
    
    vector<char> v(oper);
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    
    dfs(v, {});
    
    for(auto pr : pri){
        vector<long long> cp_con(con);
        vector<char> cp_oper(oper);
        for(auto p : pr){
            for(int i = 0; i < cp_oper.size(); i++){
                if(cp_oper[i] == p){
                    long long num = cp_con[i];
                    if(p == '-')
                        num -= cp_con[i+1];
                    else if(p == '+')
                        num += cp_con[i+1];
                    else
                        num *= cp_con[i+1];
                    
                    cp_con.erase(cp_con.begin()+i, cp_con.begin()+i+2);
                    cp_oper.erase(cp_oper.begin()+i);
                    cp_con.insert(cp_con.begin()+i, num);
                    i--;
                }
            }
        }
        answer = max(abs(cp_con.front()), answer);
    }
    
    return answer;
}