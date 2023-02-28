#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 0;
    string s = "";
    for(const auto ss : spell)
        s += ss;
    sort(s.begin(), s.end());
    for(string d : dic){
        sort(d.begin(), d.end());
        if(s == d)
            return 1;
    }
    return 2;
}