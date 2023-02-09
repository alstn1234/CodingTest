#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
    st.push(s[0]);
    for(int i = 1; i < s.length(); i++){
        if(st.empty() || st.top() != s[i])
            st.push(s[i]);
        else
            st.pop();
    }
    
    if(st.empty())
        return 1;
    return 0;
}