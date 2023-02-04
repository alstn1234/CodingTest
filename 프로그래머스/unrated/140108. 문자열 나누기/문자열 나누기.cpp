#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char val = '-';
    int a = 0;
    int b = 0;
    for(int i = 0; i < s.length(); i++){
        if(val == '-'){
            val = s[i];
            a++;
        }
        else{
            if(s[i] == val)
                a++;
            else
                b++;
        }
        if(a==b){
            answer++;
            val = '-';
        }
    }
    if(a!=b)
        answer++;
    return answer;
}