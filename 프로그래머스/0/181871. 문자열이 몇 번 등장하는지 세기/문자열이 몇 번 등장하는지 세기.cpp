#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    int n = -1;
    do{
        n = myString.find(pat, n+1);
        answer++;
    }while(n != string::npos);
    
    return answer-1;
}