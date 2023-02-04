#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;
    
    for(int i = 0; i < enemy.size(); i++){
        if(n - enemy[i] >= 0){
            n -= enemy[i];
            pq.push(enemy[i]);
            continue;
        }
        if(k-- == 0)
            return i;
        if(!pq.empty() && pq.top() > enemy[i]){
            n += pq.top();
            pq.pop();
            i--;
        }
    }
    return enemy.size();
}