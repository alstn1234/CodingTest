#include <string>
#include <vector>
#include <queue>


using namespace std;

void bfs(int start, vector<vector<int>> maps, vector<int>& visited){
    queue<int> q;
    q.push(start);
    visited[start] = 0;

    int cur;
    while(!q.empty()){
        cur = q.front(); q.pop();
        for(int map : maps[cur]){
            if(visited[map] == -1){
                q.push(map);
                visited[map] = visited[cur] + 1;
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<int> visited(n+1, -1);

    vector<vector<int>> maps(n+1, vector<int>());
    for(auto road : roads){
        maps[road[0]].emplace_back(road[1]);
        maps[road[1]].emplace_back(road[0]);
    }
    
    bfs(destination, maps, visited);
    for(auto source : sources){
        answer.emplace_back(visited[source]);
    }
    return answer;
}