#include <string>
#include <vector>

using namespace std;
long solve(int n){
    string s = "";
    while(n != 0){
        s += n%3 + '0';
        n /= 3;
    }
    return stol(s);
}
int solution(int n) {
    int answer = 0;
    long num = solve(n);
    int i = 1;
    while(num != 0){
        answer += num%10*i;
        i *= 3;
        num /= 10;
    }
    return answer;
}