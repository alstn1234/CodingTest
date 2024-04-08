#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int a, int b) {
    return ((a-b)%2 != 0) ? 2 * (a+b) : (a%2 == 1) ? a*a + b*b : abs(a - b);
}