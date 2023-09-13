#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> dx{ -1, 1, 0, 0 };
vector<int> dy{ 0, 0, -1, 1 };

void dfs(vector<vector<int>>& map, vector<vector<bool>>& visit, int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx >= 0 && xx < map.size() && yy >= 0 && yy < map[0].size() && map[xx][yy] == 1 && !visit[xx][yy])
			dfs(map, visit, xx, yy);
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<vector<int>>> map;
	for (int i = 0; i < n; i++) {
		int width, height, pos_num;
		cin >> width >> height >> pos_num;
		vector<vector<int>> v(width, vector<int>(height, 0));
		for (int j = 0; j < pos_num; j++) {
			int x, y;
			cin >> x >> y;
			v[x][y] = 1;
		}
		map.push_back(v);
	}

	vector<int> answer;

	for (auto& m : map) {
		vector<vector<bool>> visit(m.size(), vector<bool>(m[0].size(), false));
		int k = 0;
		for (int x = 0; x < m.size(); x++) {
			for (int y = 0; y < m[0].size(); y++) {
				if (m[x][y] == 1 && !visit[x][y]) {
					dfs(m, visit, x, y);
					k++;
				}
			}
		}
		answer.push_back(k);
	}

	for (const auto& a : answer)
		cout << a << endl;

	return 0;
}