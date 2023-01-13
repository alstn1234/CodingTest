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
            if(jobs[i][0] > time){
                if(time < jobs[0][0])
                    time = jobs[0][0];
                break;
            }
            n = i;
        }
        vector<int> next = jobs[0];
        for(int i = 1; i <= n; i++){
            if(next[1] >= jobs[i][1])
                next = jobs[i];
        }
        
        time += next[1];
        answer += time - next[0];
        jobs.erase(remove(jobs.begin(), jobs.end(), next), jobs.end());
    }
    return answer/size;
}