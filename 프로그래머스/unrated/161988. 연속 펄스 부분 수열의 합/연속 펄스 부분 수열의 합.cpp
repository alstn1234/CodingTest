#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    int size = sequence.size();
    vector<long long> dp(size, 0);
    dp[0] = sequence[0];
    for(int i = 1; i < size; i++){
        if(i%2==0)
            dp[i] = max(dp[i-1] + sequence[i], (long long)sequence[i]);
        else
            dp[i] = max(dp[i-1] + sequence[i]*(-1), (long long)sequence[i]*(-1));  
    } 
    answer = *max_element(dp.begin(), dp.end());
    
    dp[0] = sequence[0]*(-1);
    for(int i = 1; i < size; i++){
        if(i%2==0)
            dp[i] = max(dp[i-1] + sequence[i]*(-1), (long long)sequence[i]*(-1));
        else
            dp[i] = max(dp[i-1] + sequence[i], (long long)sequence[i]);  
    } 
    answer = max(*max_element(dp.begin(), dp.end()), answer);
    return answer;
}