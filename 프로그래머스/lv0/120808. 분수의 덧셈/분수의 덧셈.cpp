#include <string>
#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    bool b = false;
    int up = numer1*denom2 + numer2*denom1;
    int down = denom1*denom2;
    while(true){
        b = false;
        for(int i = 2; i <= min(up,down); i++){
            if(up%i == 0 && down%i == 0){
                up /= i;
                down /= i;
                b = true;
                break;
            }
        }
        if(!b)
            break;
    }
    answer.push_back(up);
    answer.push_back(down);
    return answer;
}