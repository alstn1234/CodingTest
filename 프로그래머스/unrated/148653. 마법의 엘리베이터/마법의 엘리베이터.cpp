#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey != 0){
        int a = storey%10;
        storey = storey / 10;
        if(a == 5){
            if(storey%10 >= 5){
                answer += 10-a;
                storey += 1;
            }else
                answer += a;
        }
        else if(a > 5){
            answer += 10-a;
            storey += 1;
        }else{
            answer += a;
        }
    }
    return answer;
}