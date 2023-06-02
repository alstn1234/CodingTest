#include <vector>
#include <iostream>

using namespace std;

int fact(int n, int r, vector<vector<int>>& dp) {
    if (dp[n][r])
        return dp[n][r];
    dp[n][r] = fact(n - 1, r - 1, dp) + fact(n - 1, r, dp);
    return dp[n][r];
}

int main() {
    int test_num;

    cin >> test_num;
    for (int i = 0; i < test_num; i++) {
        int n, m;
        int k = 1;
        cin >> n >> m;

        vector<vector<int>> dp(30, vector<int>(30, 0));
        for (int i = 0; i < 30; i++) {
            dp[i][0] = dp[i][i] = 1;
        }

        cout << fact(m, n, dp) << endl;

    }

}