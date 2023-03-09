#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool solve(int n){
    if(n == 2)
        return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0)
            return true;
    }
    return false;
}

int solution(int n) {
    int answer = 0;
    for(int i = 1; i <= n; i++){
        if(solve(i))
            answer++;
    }
    return answer;
}