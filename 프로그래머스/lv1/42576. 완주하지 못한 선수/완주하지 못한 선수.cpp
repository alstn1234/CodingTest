#include <string>
#include <vector>
#include <algorithm>


using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    vector<string> part = participant;
    vector<string> com = completion;
    sort(part.begin(), part.end());
    sort(com.begin(), com.end());
    for(int i = 0; i < com.size(); i++){
        if(part[i]!=com[i]){
            answer=part[i];
                break;
            }
        if(com.size()-1==i){
            answer=part[i+1];
                break;
        }
    }
    return answer;
}