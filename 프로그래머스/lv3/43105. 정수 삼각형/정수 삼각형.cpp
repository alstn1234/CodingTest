#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer = 0;

void bfs(vector<vector<int>> triangle){
    queue<pair<int, int>> q;
    q.push(pair<int, int>(0, 0));
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x < triangle.size() - 1){
            if((y == 0) || (triangle[x][y] > triangle[x][y - 1])){
                q.push(pair<int, int>(x + 1, y));
                triangle[x + 1][y] += triangle[x][y];
            }
            if((y == triangle[x].size() - 1) || (triangle[x][y] > triangle[x][y + 1])){
                q.push(pair<int, int>(x + 1, y + 1));
                triangle[x + 1][y + 1] += triangle[x][y];
            }
        }
        else{
            answer = max(answer, triangle[x][y]);
        }
    }
}

int solution(vector<vector<int>> triangle){
    bfs(triangle);
    return answer;
}