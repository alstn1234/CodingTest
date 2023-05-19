#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visited;

void bfs(vector<vector<int>> computers, int computer){
    queue<int> q;
    q.push(computer);
    visited[computer] = true;
    while(!q.empty()){
        int idx = q.front(); q.pop();
        for(int i = 0; i < computers[idx].size(); i++){
            if(computers[idx][i] == 1 && visited[i] == false){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visited.assign(n, false);
    for(int i = 0; i < visited.size(); i++){
        if(visited[i] == false){
            bfs(computers, i);
            answer++;
        }
    }
    return answer;
}