#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 1000000; i > 0; i = i / 10){
        answer += n / i;
        n = n % i;
    }
    return answer;
}