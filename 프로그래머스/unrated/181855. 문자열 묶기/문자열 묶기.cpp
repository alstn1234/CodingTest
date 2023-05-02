#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> strArr) {
    int answer = 0;
    map<int, int> m;
    
    for(auto s : strArr)
        answer = max(++m[s.size()], answer);
    
    return answer;
}