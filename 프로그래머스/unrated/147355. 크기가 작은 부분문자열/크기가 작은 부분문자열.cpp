#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for(int i = 0; i < t.length()-p.length()+1; i++){
        string num = t.substr(i, p.length());
        for(int n = 0; n < num.length(); n++){
            if(p[n] < num[n])
                break;
            if(p[n] > num[n]){
                answer++;
                break;
            }
            if(p[n] == num[n] && n == num.length()-1){
                answer++;
                break;
            }
        }
    }
    return answer;
}