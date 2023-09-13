#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(vector<vector<int>>& map, vector<int>& v, int x, vector<bool>& d_visit) {
	d_visit[x] = true;
	v.push_back(x);
	for (const auto& m : map) {
		if (m[0] == x && !d_visit[m[1]]) {
			dfs(map, v, m[1], d_visit);
		}
		if (m[1] == x && !d_visit[m[0]]) {
			dfs(map, v, m[0], d_visit);
		}
	}
}

void bfs(vector<vector<int>>& map, vector<int>& v, int x, vector<bool>& b_visit) {
	queue<int> q;
	q.push(x);
	b_visit[x] = true;

	while (!q.empty()) {
		int n = q.front();
		q.pop();
		v.push_back(n);

		for (const auto& m : map) {
			if (m[0] == n && !b_visit[m[1]]) {
				q.push(m[1]);
				b_visit[m[1]] = true;
			}
			if (m[1] == n && !b_visit[m[0]]) {
				q.push(m[0]);
				b_visit[m[0]] = true;
			}
		}
	}
}

int main() {
	vector<vector<int>> map;
	int n, m, start;
	cin >> n;
	cin >> m;
	cin >> start;
	for (int i = 0; i < m; i++) {
		vector<int> v;
		int a, b;
		cin >> a;
		cin >> b;
		if (a > b)
			swap(a, b);
		v.push_back(a);
		v.push_back(b);
		map.push_back(v);
	}

	sort(map.begin(), map.end());

	vector<int> dfs_map;
	vector<int> bfs_map;
	vector<bool> d_visit(n + 1, false);
	vector<bool> b_visit(n + 1, false);

	dfs(map, dfs_map, start, d_visit);
	bfs(map, bfs_map, start, b_visit);

	for (const auto d : dfs_map)
		cout << d << " ";
	cout << endl;
	for (const auto b : bfs_map)
		cout << b << " ";
	cout << endl;
}