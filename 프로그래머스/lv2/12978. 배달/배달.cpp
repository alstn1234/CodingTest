#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int answer = 0;

void bfs(vector<vector<int>> road, int K){
    vector<int> visit(51, K+1);
    queue<int> q;
    visit[1] = 0;
    q.push(1);
    
    while(!q.empty()){
        int pos;
        pos = q.front(); q.pop();
        for(auto r : road){
            if(r[0] == pos && visit[r[1]] > visit[pos]+r[2]){
                q.push(r[1]);
                visit[r[1]] = visit[pos] + r[2];
            }
            if(r[1] == pos && visit[r[0]] > visit[pos]+r[2]){
                q.push(r[0]);
                visit[r[0]] = visit[pos] + r[2];
                
            }
        }
    }
    for(auto v : visit){
        if(v <= K)
            answer++;
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    bfs(road, K);
    return answer;
}