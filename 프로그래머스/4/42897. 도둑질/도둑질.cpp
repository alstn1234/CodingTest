#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    vector<int> dp(money.size(), 0);
    vector<int> dp2(money.size(), 0);
    dp[0] = money[0];
    dp2[1] = money[1];
    dp[2] = money[2]+dp[0];
    dp2[2] = money[2];
    for(int i = 3; i < dp.size(); i++){
        dp2[i] = max(money[i]+dp2[i-3], money[i]+dp2[i-2]);
        if(i != dp.size()-1)
            dp[i] = max(money[i]+dp[i-3], money[i]+dp[i-2]);
        answer = max(answer, max(dp[i], dp2[i]));
    }
    return answer;
}