#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    
    for(string pic : picture){
        string s = "";
        for(const char p : pic){
            for(int i = 0; i < k; i++){
                if(p == '.')
                    s += ".";
                else
                    s += "x";
            }
        }
        for(int i = 0; i < k; i++)
            answer.push_back(s);
    }
    return answer;
}