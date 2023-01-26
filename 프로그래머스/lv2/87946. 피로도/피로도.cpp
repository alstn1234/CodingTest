#include <string>
#include <vector>

using namespace std;
int answer = 0;

void dfs(int k, vector<vector<int>> dun, int count, vector<bool> visited){
    for(int i = 0; i < dun.size(); i++){
        if(visited[i])
            continue;
        if(dun[i][0] <= k){
            visited[i] = true;
            dfs(k - dun[i][1], dun, ++count, visited);
            visited[i] = false;
            count--;
        }
    }
    answer = max(answer, count); 
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(8, false);
    dfs(k, dungeons, 0, visited);
    return answer;
}