#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int index = 0;
    int count = 0;
    priority_queue<int> pq;
    pq.push(1);
    sort(tangerine.begin(), tangerine.end());
    for(int i = 1; i < tangerine.size(); i++){
        if(tangerine[i] != tangerine[i - 1]){
            pq.push(i - index);
            index = i;
        }
        if(i == tangerine.size() - 1){
            pq.push(i - index + 1);
        }
    }
    
    while(count < k && !pq.empty()){
        count += pq.top();
        pq.pop();
        answer++;
    }
    return answer;
}