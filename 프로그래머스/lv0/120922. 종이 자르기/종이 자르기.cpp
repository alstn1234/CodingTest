#include <string>
#include <vector>

using namespace std;

int solution(int M, int N) {
    int answer = 0;
    if(M > N)
        return (N-1) + N*(M-1);
    else
        return (M-1) + M*(N-1);
}