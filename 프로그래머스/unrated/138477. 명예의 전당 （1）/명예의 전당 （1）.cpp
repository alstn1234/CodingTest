#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto s : score){
        if(pq.size() < k)
            pq.push(s);
        else if(pq.size() == k && s > pq.top()){
            pq.pop();
            pq.push(s);
        }
        answer.push_back(pq.top());
    }
    
    return answer;
}