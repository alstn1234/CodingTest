#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq(works.begin(), works.end());
    int first, second, diff;
    while(n > 0){
        first = pq.top(); pq.pop();
        if(first == 0) break;
        second = pq.top();
        diff = first - second;
        if(second > 0) diff++;
        if(n >= diff){
            first -= diff;
            n -= diff;
        }
        else{
            first -= n;
            n = 0;
        }
        pq.push(first);
    }
    while(!pq.empty()){
        first = pq.top(); pq.pop();
        answer += first * first;
    }
    return answer;
}