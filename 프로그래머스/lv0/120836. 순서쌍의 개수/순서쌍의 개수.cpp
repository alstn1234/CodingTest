#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solve(int n){
    int answer = 0;
    for(int i = 1; i <= n; i++){
        if(n%i == 0)    
            answer++;
    }
    return answer;
}

int solution(int n) {
    return solve(n);
}