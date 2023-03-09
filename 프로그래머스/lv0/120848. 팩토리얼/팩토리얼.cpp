#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int num = 1;
    while(num <= n){
        num *= ++answer;
    }
    return answer-1;
}