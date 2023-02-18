#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string my_string) {
    string answer = "";
    map<char, int> m;
    for(const char s : my_string){
        m[s]++;
        if(m[s] == 1)
            answer += s;
    }
    return answer;
}