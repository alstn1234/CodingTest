#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int cnt = 0;
    int all_cnt = 0;
    while(all_cnt != progresses.size()){
        for(int i = 0+ all_cnt; i < progresses.size(); i++)
            progresses[i] += speeds[i];
        cnt = 0;
        for(int i = 0 + all_cnt; i < progresses.size(); i++){
            if(progresses[i] >= 100){
                cnt++;
                all_cnt++;
            }else{
                break;
            }
        }
        if(cnt > 0)
            answer.push_back(cnt);
        
    }
    return answer;
}