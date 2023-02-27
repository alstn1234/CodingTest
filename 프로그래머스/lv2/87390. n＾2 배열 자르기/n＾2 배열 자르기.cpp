#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    long long i = left/n;
    long long j = left%n;
    while(right >= (i)*n+j){
        answer.push_back(max(i+1, j+1));
        if(n-1 == j){
            i++; j = 0;
        }else
            j++;
    }
    return answer;
}