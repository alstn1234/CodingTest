#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dx{ -1, 1, 0, 0 };
vector<int> dy{ 0, 0, 1, -1 };

void dfs(vector<string>& map, vector<vector<bool>>& visit, int x, int y, int& n) {
	visit[x][y] = true;
	n++;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx >= 0 && xx < visit.size() && yy >= 0 && yy < visit.size() && !visit[xx][yy] && map[xx][yy] == '1') {
			dfs(map, visit, xx, yy, n);
		}
	}
}

int main() {
	vector<string> map;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		map.push_back(s);
	}

	vector<vector<bool>> visit(n, vector<bool>(n, false));
	vector<int> home;
	int home_num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1' && !visit[i][j]) {
				int n = 0;
				dfs(map, visit, i, j, n);
				home.push_back(n);
				home_num++;
			}
		}
	}
	
    sort(home.begin(), home.end());
    
	cout << home_num << endl;
	for (const auto& h : home)
		cout << h << endl;

	return 0;
}