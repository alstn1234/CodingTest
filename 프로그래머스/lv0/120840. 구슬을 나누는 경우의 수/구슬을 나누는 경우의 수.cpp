#include <string>
#include <vector>

using namespace std;


int solution(int balls, int share) {
    long long top = 1;
    long long b = balls;
    for(int i = 1; i <= min(share, balls-share); i++){
        top *= b--;
        top /= i;
    }
    return top;
}