#include <string>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(vector<string> v1, vector<string> v2){
    return v1[1] < v2[1];
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<string> st;
    map<string, int> m;
    sort(plans.begin(), plans.end(), cmp);
    int time = 0;
    
    for(auto plan : plans){
        int next_time = stoi(plan[1].substr(0,2))*60+stoi(plan[1].substr(3,2));
        while(!st.empty()){
            string s = st.top(); st.pop();
            int times = m[s];
            m[s] -= next_time - time;
            if(m[s] <= 0){
                answer.push_back(s);
                time += times;
            }
            else{
                st.push(s);
                break;
            }
        }
        time = next_time;
        m[plan[0]] = stoi(plan[2]);
        st.push(plan[0]);
    }
    while(!st.empty()){
        answer.push_back(st.top());
        st.pop();
    }
    return answer;
}