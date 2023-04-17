#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    for(long long x = 1; x < r2; x++){
        long long y2 = sqrt((long long)r2*r2 - x*x);
        long long y1 = sqrt((long long)r1*r1 - x*x);
        if(y1*y1 + x*x == (long long)r1*r1 && y1 != 0)
            y1 -= 1;
        long long y = y2 - y1;
        answer += y;
    }
    answer *= 4;
    answer += 4*(r2-r1+1);
    return answer;
}