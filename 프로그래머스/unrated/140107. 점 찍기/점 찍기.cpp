#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long dd = (long long)d * d;
    for(int i = 0; i <= d; i += k){
        int y = sqrt(dd - (long long)i*i);
        answer += y/k + 1;
    }
    return answer;
}