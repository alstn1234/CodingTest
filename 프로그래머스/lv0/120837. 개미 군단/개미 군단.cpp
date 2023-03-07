#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    while(hp >= 5){
        hp -= 5;
        answer++;
    }
    while(hp >= 3){
        hp -= 3;
        answer++;
    }
    while(hp >= 1){
        hp -= 1;
        answer++;
    }
    return answer;
}