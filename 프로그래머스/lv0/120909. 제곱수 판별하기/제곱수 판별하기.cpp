#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    auto a = sqrt(n);
    for(int i = 0; i <= 1000; i++)
        if(a == i)
            return 1;
    
    return 2;
}