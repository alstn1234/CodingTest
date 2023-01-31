#include <string>
#include <vector>
#include <queue>

using namespace std;
int bfs(vector<vector<int>> v, int n) {
    int cnt = 0;
    queue<int> q;
    vector<bool> visit(n+1, false);
    q.push(v[0][0]);
    visit[v[0][0]] = true;

    while (!q.empty()) {
        
        int a = q.front();
        q.pop();
        if (a == 0)
            continue;
        cnt++;
        for (int i = 0; i < v.size(); i++) {
            if (v[i][0] == a && !visit[v[i][1]]) {
                q.push(v[i][1]);
                visit[v[i][1]] = true;
            }
            if (v[i][1] == a && !visit[v[i][0]]) {
                q.push(v[i][0]);
                visit[v[i][0]] = true;
            }
        }
    }
    if (n-2*cnt > 0)
        return n-2*cnt;
    else
        return -(n-2*cnt);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    for (int i = 0; i < wires.size(); i++) {
        vector<vector<int>> wires_cp = wires;
        wires_cp[i][1] = 0;
        answer = min(answer, bfs(wires_cp, n));
    }
    return answer;
}