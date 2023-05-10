#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    vector<vector<int>> dp(board.size()+1, vector<int>(board[0].size()+1, 0));
    
    for(int i = 1; i <= board.size(); i++){
        for(int j = 1; j <= board[0].size(); j++){
            if(board[i-1][j-1] == 1){
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                answer = max(answer, dp[i][j]);
            }
        }
    }
    return answer*answer;
}