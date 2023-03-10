#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.length() == 4 || s.length() == 6){
        for(const char c : s){
            if(c < '0' || c > '9')
                return false;
        }
        return true;
    }
    return false;
}