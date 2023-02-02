#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for(int i = 0; i < s.length(); i++){
        for(int n = 0; n < index; n++){
            if(++s[i] > 'z')
                s[i] = 'a';
            for(int j = 0; j < skip.length(); j++){
                if(s[i] == skip[j]){
                    if(++s[i] > 'z')
                        s[i] = 'a';
                    j = -1;
                }
            }
        }
    }
    return s;
}