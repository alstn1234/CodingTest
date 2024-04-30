#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 11;
void dfs(string word, string target, vector<string> words, int count){
    if(word == target)
        answer = min(answer, count);
    
    for(auto w : words){
        int diffCount = 0;
        for(int i = 0; i < w.length(); i++){
            if(word[i] != w[i]) diffCount++;
            if(diffCount > 1) break;
            
            if(i == w.length() - 1){
                vector<string> v(words.begin(), words.end());
                v.erase(find(v.begin(), v.end(), w));
                dfs(w, target, v, count + 1);
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, words, 0);
    
    return answer%11;
}