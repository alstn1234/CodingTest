#include<vector>
#include <queue>

using namespace std;

vector<int> v({ -1, 1 });


int bfs(vector<vector<int> > maps, vector<vector<int>>& visit) {
    queue<pair<int, int>> q;
    q.push(pair<int, int>(0, 0));
    visit[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < v.size(); i++) {
            if (x + v[i] >= 0 && x + v[i] < maps.size() && maps[x + v[i]][y] == 1 && visit[x + v[i]][y] == -1) {
                q.push(pair<int, int>(x + v[i], y));
                visit[x + v[i]][y] = visit[x][y] + 1;
            }
            if (y + v[i] >= 0 && y + v[i] < maps[0].size() && maps[x][y + v[i]] == 1 && visit[x][y + v[i]] == -1) {
                q.push(pair<int, int>(x, y + v[i]));
                visit[x][y + v[i]] = visit[x][y] + 1;
            }
        }
    }
    return visit[ maps.size()-1][maps[0].size()-1];
}

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    vector<vector<int>> visit(maps.size(), vector<int>(maps[0].size(), -1));
    answer = bfs(maps, visit);
    return answer;
}