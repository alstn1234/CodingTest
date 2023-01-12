#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int size = jobs.size();
    
    sort(jobs.begin(), jobs.end());
    time += (jobs[0][1] + jobs[0][0]);
    answer += time - jobs[0][0];
    jobs.erase(jobs.begin());
    
    while(!jobs.empty()){
        int n = 0;
        for(int i = 0; i < jobs.size(); i++){
            if(jobs[i][0] <= time){
                n = i;
                continue;
            }
            if(time < jobs[0][0])
                time = jobs[0][0];
            break;
        }
        
        int next = 0;
        for(int i = 1; i <= n; i++){
            if(jobs[next][1] >= jobs[i][1])
                next = i;
        }
            
        time += jobs[next][1];
        answer += (time - jobs[next][0]);
        jobs.erase(jobs.begin()+next);
    }
    return answer/size;
}