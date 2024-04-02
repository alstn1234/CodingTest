#include <vector>
#include <queue>

using namespace std;

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {-1, 1, 0, 0};

void bfs(vector<vector<int>>& picture, vector<vector<bool>>& visited, int& maxSize, int x, int y){
    int height = picture.size(), width = picture[0].size();
    int areaSize = 0;
    int colorNum = picture[x][y];
    queue<pair<int, int>> q;
    q.push(pair<int, int>(x, y));
    visited[x][y] = true;
    
    while(!q.empty()){
        auto pos = q.front();
        q.pop(); areaSize++;
        int posX = pos.first, posY = pos.second;
        
        for(int i = 0; i < 4; i++){
            int curX = posX + dx[i];
            int curY = posY + dy[i];
            if(curX >= 0 && curX < height && curY >= 0 && curY < width 
               && !visited[curX][curY] && colorNum == picture[curX][curY]){
                q.push(pair<int, int>(curX, curY));
                visited[curX][curY] = true;
            }
        }
    }
    maxSize = max(maxSize, areaSize);
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false)) ;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(picture[i][j] != 0 && !visited[i][j]){
                bfs(picture, visited, max_size_of_one_area, i, j);
                number_of_area++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
