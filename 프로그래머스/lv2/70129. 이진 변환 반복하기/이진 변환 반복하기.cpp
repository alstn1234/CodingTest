#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2,0);
    int zero = 0, one = 0;
    int num;
    for(int i = 0; i < s.length(); i++){
        if(s[i]=='0')
            zero++;
        else
            one++;
    }
    answer[1] += zero;
    num = one;
    answer[0]++;
    while(num != 1){
        zero=0; one=0;
        int num2 = num;
        while(num2 != 0){
            if(num2%2==1)
                one++;
            else
                zero++;
            num2 /= 2;
        }
        answer[1] += zero;
        answer[0]++;
        num=one;
    }
    return answer;
}