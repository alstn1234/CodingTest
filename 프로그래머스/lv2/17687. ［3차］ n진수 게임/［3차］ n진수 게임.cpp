#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solve(int n, int size){
    string s = "0";
    for(int i = 1; i <= 1000000; i++){
        while(size < s.length()){
            s.erase(s.length()-1);
        }
        if(size == s.length())
            break;
        int p = i;
        string ss = "";
        while(p != 0){
            int m = p%n;
            if(m >= 10){
                ss += 'A'+(m-10);
                p /= n;
            }
            else{
            ss += m + '0';
            p /= n;
            }
        }
        reverse(ss.begin(), ss.end());
        s += ss;
    }
    return s;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string s = solve(n, t*m);
    for(int i = p-1; i < s.length(); i+=m)
        answer += s[i];
    
    return answer;
}