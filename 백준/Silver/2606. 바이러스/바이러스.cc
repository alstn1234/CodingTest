#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& map, vector<bool>& visit, int& n, int x) {
	visit[x] = true;
	for (const auto& m : map) {
		if (m[0] == x && !visit[m[1]]) {
			n++;
			dfs(map, visit, n, m[1]);
		}
		if (m[1] == x && !visit[m[0]]) {
			n++;
			dfs(map, visit, n, m[0]);
		}
	}
}

int main() {
	vector<vector<int>> map;
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		vector<int> v;
		int a, b;
		cin >> a;
		cin >> b;
		v.push_back(a);
		v.push_back(b);
		map.push_back(v);
	}

	vector<bool> visit(n + 1, false);
	int num = 0;
	dfs(map, visit, num, 1);

	cout << num;

	return 0;
}