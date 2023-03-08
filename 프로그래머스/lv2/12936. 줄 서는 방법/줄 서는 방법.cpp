#include <string>
#include <vector>

using namespace std;

long long fac(int n){
    vector<long long> dp(n+1, 0);
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-1]*i;
    return dp[n];
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> v;
    for(int i = 1; i <= n; i++)
        v.push_back(i);
    k--;
    while(n != 1){
        long long f = fac(--n);
        answer.push_back(v[k/f]);
        v.erase(v.begin()+k/f);
        k %= f;
    }
    answer.push_back(v[0]);
    return answer;
}