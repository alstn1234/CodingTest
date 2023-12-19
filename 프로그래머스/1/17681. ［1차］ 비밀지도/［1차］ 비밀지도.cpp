#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int idx = 0; idx < n; idx++){
        string str = "";
        int num1 = arr1[idx], num2 = arr2[idx];
        for(int i = n - 1; i >= 0; i--){
            char c = ' ';
            int powNum = pow(2, i);
            
            if(num1 - powNum >= 0) {
                c = '#';
                num1 -= powNum;
            }
            if(num2 - powNum >= 0) {
                c = '#';
                num2 -= powNum;
            }
            str += c;
        }
        answer.push_back(str);
    }
    return answer;
}