#include <string>
#include <vector>
#include <stack>

using namespace std;

// 올바른 괄호 문자열 판별
bool IsCorrect(string p){
    stack<char> s;
    for(const char c : p){
        if(c == '(')
            s.push('(');
        else if(c == ')'){
            if(s.empty())
                return false;
           s.pop(); 
        }
    }
    if(!s.empty())
        return false;
    return true;
}

// 균형잡힌 괄호 문자열 판별
bool IsBalance(string p){
    int m = 0, n = 0;
    for(const char c : p){
        if(c == '(') m++;
        else n++;
    }
    if(m == n)
        return true;
    return false;
}

string solve(string p){
    string answer = "";
    string remain = "";
    int m = 0, n = 0;
    if(IsCorrect(p) || p == "")
        return p;
    for(int i = 0; i < p.length(); i++){
        if(p[i] == '(') m++;
        else n++;
        answer += p[i];
        if(m == n){
            remain = p.substr(i+1, p.length()-i);
            break;
        }
    }
    if(IsCorrect(answer)){
        answer += solve(remain);
        return answer;
    }
    
    else{
        string s = "(";
        s += solve(remain);
        s += ')';
        answer = answer.substr(1, answer.length()-2);
        for(int i = 0; i < answer.length(); i++){
            if(answer[i] == '(')
                answer[i] = ')';
            else
                answer[i] = '(';
        }
        s += answer;
        return s;
    }
}

string solution(string p) {
    string answer = "";
    if(p == "" || IsCorrect(p))
        return p;
    return solve(p);
}