#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for(int i = 0; i < signs.size(); i++){
        int sign = 1;
        if(!signs[i])
            sign = -1;
        answer += absolutes[i]*sign;
    }
    return answer;
}