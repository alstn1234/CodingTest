#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> m;
    for(string s : keymap){
        for(int i = 0; i < s.length(); i++){
            if(m.find(s[i]) != m.end())
                if(m[s[i]] < i+1)
                    continue;
            m[s[i]] = i+1;
        }
    }
    
    for(string t : targets){
        int cnt = 0;
        for(int i = 0; i < t.length(); i++){
            cnt += m[t[i]];
        }
        if(cnt == 0)
            cnt = -1;
        answer.push_back(cnt);
    }
    return answer;
}