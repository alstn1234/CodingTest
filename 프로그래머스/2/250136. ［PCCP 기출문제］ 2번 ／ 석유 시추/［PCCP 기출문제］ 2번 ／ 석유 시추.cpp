#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int idx = 0;
vector<int> dx = {-1, 0, 0, 1};
vector<int> dy = {0, 1, -1, 0};

void bfs(vector<vector<int>> &land, vector<vector<int>> &visited, map<int, int> &oilSize, int x, int y){
    idx++;
    queue<pair<int, int>> q;
    q.push(pair<int, int>(x, y));
    visited[x][y] = idx;
    oilSize[idx]++;
    
    while(!q.empty()){
        auto pos = q.front();
        q.pop();
        int curX = pos.first;
        int curY = pos.second;
        
        for(int i = 0; i <= 3; i++){
            int row = curX + dx[i];
            int col = curY + dy[i];
            
            if(row >= 0 && row < land.size() && col >= 0 && col < land[0].size() 
               && visited[row][col] == 0 && land[row][col] == 1){
                visited[row][col] = idx;
                oilSize[idx]++;
                q.push(pair<int, int>(row, col));
            }
        }
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    map<int, int> oilSize;
    vector<vector<int>> visited(land.size(), vector<int>(land[0].size(), 0));
    
    for(int i = 0; i < land[0].size(); i++){
        set<int> oil;
        for(int j = 0; j < land.size(); j++){
            if(land[j][i] == 1){
                if(visited[j][i] == 0){
                    bfs(land, visited, oilSize, j, i);
                }
                oil.insert(visited[j][i]);
            }
        }
        int oliSum = 0;
        for(auto o : oil){
            oliSum += oilSize[o]; 
        }
        answer = max(answer, oliSum);
    }
    return answer;
}