#include <string>
#include <vector>
#include <map>


using namespace std;

int cnt = 0;
map<string, int> m;

void dfs(string s){
    if(s.length() == 6)
        return;
    m[s] = cnt++;
    dfs(s+'A');
    dfs(s+'E');
    dfs(s+'I');
    dfs(s+'O');
    dfs(s+'U');
}

int solution(string word) {
    int answer = 0;
    dfs("");
    return m[word];
}