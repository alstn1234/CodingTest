#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int n = -1;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            n = -1;
            continue;
        }
        if(++n%2 == 0)
            s[i] = toupper(s[i]);
        else
            s[i] = tolower(s[i]);
    }
    return s;
}