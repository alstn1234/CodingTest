#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    for(int i = 1; i <= n/2; i++){
        int sum = 0, k = i;
        while(sum < n){
            sum += k++;
            if(sum==n)
                answer++;
        }
    }
    return answer;
}