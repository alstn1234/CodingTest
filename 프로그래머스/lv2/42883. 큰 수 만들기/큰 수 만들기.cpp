#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    int i = 0;
    while(k != 0){
        if(number[i] < number[i+1]){
            number.erase(i,1);
            k--;
            i = -1;
        }
        if(k == 0)
            break;
        if(++i >= number.length()){
            while(k != 0){
                number.pop_back();
                k--;
            }
        }
    }
    return number;
}