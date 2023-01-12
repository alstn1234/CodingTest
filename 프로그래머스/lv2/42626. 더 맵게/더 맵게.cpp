#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pri_que;
    for(int i = 0; i < scoville.size(); i++)
        pri_que.push((long long)scoville[i]);
    
    while(pri_que.top() < K && pri_que.size() >= 2){
            long long a, b;
            a = pri_que.top();
            pri_que.pop();
            b = pri_que.top();
            pri_que.pop();
            pri_que.push(a+(b*2));
            answer++;
    }
    if(pri_que.size() == 1 && pri_que.top() < K)
        answer = -1;
    return answer;
}