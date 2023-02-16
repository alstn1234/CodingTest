#include <string>
#include <vector>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    for(string s : s1){
        for(string ss : s2){
            if(s==ss){ 
                answer++;
                break;           
            }
        }
    }
    return answer;
}