#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

int bfs(vector<string> maps, int sx, int sy, int ax, int ay){
    int size = maps.size()*maps[0].size();
    vector<vector<int>> visit(maps.size(), vector<int>(maps[0].size(), 0));
    queue<pair<int, int>> q;
    q.push(pair<int,int>(sx,sy));
    
    while(!q.empty()){
        if(visit[ax][ay] != 0)
            return visit[ax][ay];
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        for(int i = 0; i < dx.size(); i++){
            int x = xx+dx[i];
            int y = yy+dy[i];
            if(x < 0 || y < 0 || x >= maps.size() || y >= maps[0].size() || 
               maps[x][y] == 'X' || visit[x][y] != 0)
                continue;
            q.push(pair<int,int>(x,y));
            visit[x][y] = visit[xx][yy] + 1;
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    int sx, sy, lx, ly, ex, ey;
    
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j <maps[0].size(); j++){
            if(maps[i][j] == 'S'){
                sx = i; sy = j;
            }
            else if(maps[i][j] == 'L'){
                lx = i; ly = j;
            }
            else if(maps[i][j] == 'E'){
                ex = i; ey = j;
            }
        }
    }
    int l = bfs(maps, sx, sy, lx, ly);
    if(l == -1)
        return -1;
    int e = bfs(maps, lx, ly, ex ,ey);
    if(e == -1)
        return -1;
    return l + e;
}