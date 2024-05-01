#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    vector<vector<bool>> puddle(m+1, vector<bool>(n+1, false));
    for(auto p : puddles)
        puddle[p[0]][p[1]] = true;
    
    dp[1][0] = 1;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(puddle[i][j]) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= 1000000007;
        }
    }
    
    return dp[m][n];
}