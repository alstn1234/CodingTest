#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int xx = x;
    int sum = 0;
    while(xx != 0){
        sum += xx%10;
        xx /= 10;
    }
    return x%sum == 0 ? true : false;
}