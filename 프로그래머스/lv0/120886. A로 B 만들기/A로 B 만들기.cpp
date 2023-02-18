#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string before, string after) {
    map<char, int> m;
    for(const char b : before)
        m[b]++;
    for(const char a : after)
        m[a]--;
    for(auto iter = m.begin(); iter != m.end(); iter++){
        if(iter->second < 0)
            return 0;
    }
    return 1;
}