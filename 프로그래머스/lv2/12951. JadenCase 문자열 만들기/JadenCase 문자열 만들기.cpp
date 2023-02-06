#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    s[0] = toupper(s[0]);
    for(int i = 1; i < s.length(); i++){
        if(s[i] != ' ')
            s[i] = tolower(s[i]);
        
        if(s[i-1] == ' ')
            s[i] = toupper(s[i]);
    }
    return s;
}