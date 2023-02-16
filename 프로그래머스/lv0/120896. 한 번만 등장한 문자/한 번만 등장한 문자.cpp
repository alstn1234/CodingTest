#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    map<char, int> m;
    for(const char ss : s){
        m[ss]++;
    }
    for(auto it = m.begin(); it != m.end(); it++){
        if(it->second == 1)
            answer += it->first;
    }
    return answer;
}