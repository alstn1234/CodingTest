#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    int maxCookie = accumulate(cookie.begin(), cookie.end(), 0)/2;
    for(int i = 1; i < cookie.size(); i++){
        int n = 0, m = 0;
        int mIdx = i-1;
        int nIdx = i;
        while(true){
            if(m > maxCookie || n > maxCookie) break;
            if(n < m){
                if(--nIdx < 0) break;
                n += cookie[nIdx];
            }
            else if(n > m){
                if(++mIdx >= cookie.size()) break;
                m += cookie[mIdx];
            }
            else{
                if(++mIdx >= cookie.size()){
                    if(--nIdx < 0) break;
                    n += cookie[nIdx];
                }
                else{
                    m += cookie[mIdx];
                }
            }
            if(n==m) answer = max(answer, n);
        }
    }
    return answer;
}