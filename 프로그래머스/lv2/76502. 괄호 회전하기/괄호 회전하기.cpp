#include <string>
#include <vector>
#include <stack>

using namespace std;

bool solve(string s){
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '[' || s[i] == '(' || s[i] == '{')
            st.push(s[i]);
        if(st.empty())
            return false;
        if(s[i] == ']'){
            if(st.top() != '[')
                return false;
            st.pop();
        }
        if(s[i] == '}'){
            if(st.top() != '{')
                return false;
            st.pop();
        }
        if(s[i] == ')'){
            if(st.top() != '(')
                return false;
            st.pop();
        }
    }
    if(!st.empty())
            return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    for(int i = 0; i < s.length(); i++){
        s += s[0];
        s.erase(0,1);
        if(solve(s))
            answer++;
    }
    
    return answer;
}