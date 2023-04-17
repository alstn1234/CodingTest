#include <string>
#include <vector>

using namespace std;

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

vector<vector<int>> visit(100, vector<int>(100, -1));

void dfs(vector<string> board, int x, int y, int count, int dir){
    int cnt = 0;
    int width = board[0].size()-1, height = board.size()-1;
    int xx = x, yy = y;
    while(1){
        if(dir == -1)
            break;
        if(x+dx[dir] < 0 || x+dx[dir] > height || y+dy[dir] < 0 || y+dy[dir] > width ||
          board[x+dx[dir]][y+dy[dir]] == 'D'){
            if(cnt == 0 || (visit[x][y] <= count && visit[x][y] != -1))
                return;
            visit[x][y] = count;
            break;
        }
        x += dx[dir]; y += dy[dir]; cnt++;
    }
    if(dir != 1)
        dfs(board, x, y, count + 1, 0);
    if(dir != 0)
        dfs(board, x, y, count + 1, 1);
    if(dir != 3)
        dfs(board, x, y, count + 1, 2);
    if(dir != 2)
        dfs(board, x, y, count + 1, 3);
}

int solution(vector<string> board) {
    int x = -1, y = -1, gx = -1, gy = -1;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == 'R'){
                x = i; y = j;
                break;
            }
            if(board[i][j] == 'G'){
                gx = i; gy = j;
            }
        }
    }
    visit[x][y] = 0;
    dfs(board, x, y, 0, -1);
    return visit[gx][gy];
}