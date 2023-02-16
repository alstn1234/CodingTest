#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n >= a){
        int m = (n/a)*b;
        n = m + n%a;
        answer += m;
    }
    return answer;
}