#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    char kk = k + '0';
    for(int n = i; n <= j; n++){
        string nn = to_string(n);
        for(int m = 0; m < nn.length(); m++){
            if(nn[m] == kk)
                answer++;
        }
    }
    return answer;
}