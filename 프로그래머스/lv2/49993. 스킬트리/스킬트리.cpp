#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(string skills : skill_trees){
        map<char, int> m;
        for(int i = 0; i < skills.length(); i++){
            m[skills[i]] = i+1; 
        }
        
        int n = -1;
        for(char s : skill){
            if((n == 0 && m[s] != 0) || (m[s] != 0 && n > m[s])){
                answer--;
                break;
            }
            n = m[s];
        }
        answer++;
    }

    return answer;
}