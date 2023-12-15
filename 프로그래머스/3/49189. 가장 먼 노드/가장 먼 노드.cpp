#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<int, int> m;
vector<bool> visited(50001, false);
int count = 1;

void bfs(vector<vector<int>> edge){
    queue<pair<int, int>> q;
    q.push(pair<int, int>(1, 0));
    visited[1] = true;
    
    while(!q.empty()){
        int n = q.front().first;
        count = q.front().second;
        q.pop();
        
        for(int idx = 0; idx < edge.size(); idx++){
            if(edge[idx][0] == n && !visited[edge[idx][1]]){
                q.push(pair<int, int>(edge[idx][1], count + 1));
                visited[edge[idx][1]] = true;
                m[count + 1]++;
                edge.erase(edge.begin() + idx--);
            }
            else if(edge[idx][1] == n && !visited[edge[idx][0]]){
                q.push(pair<int, int>(edge[idx][0], count + 1));
                visited[edge[idx][0]] = true;
                m[count + 1]++;
                edge.erase(edge.begin() + idx--);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    bfs(edge);
    return m[count];
}