#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<int>> dp(N+1, vector<int>(3, 0));
	dp[0][0] = 0; dp[1][0] = 0; dp[2][0] = 0;
	for (int i = 1; i <= N; i++) {
		int r, g, b;
		cin >> r >> g >> b;		
		dp[i][0] = std::min(dp[i - 1][1], dp[i - 1][2]) + r;
		dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][2]) + g;
		dp[i][2] = std::min(dp[i - 1][0], dp[i - 1][1]) + b;
	}

	cout << std::min(dp[N][0], std::min(dp[N][1], dp[N][2]));

	return 0;
}