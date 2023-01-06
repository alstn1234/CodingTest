#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stack;
    bool answer = true;
    for(int i = 0; i < s.length(); i++){
        switch(s[i]){
            case '(':
                stack.push('(');
                break;
            case ')':
                if(stack.empty())
                    return false;
                stack.pop();
                break;
        }
    }
    if(stack.empty())
        return true;
    return false;
}