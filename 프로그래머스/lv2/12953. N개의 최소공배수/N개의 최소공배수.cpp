#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    int a = *max_element(arr.begin(), arr.end());
    for(int i = a; i < 2100000000; i++){
        bool b = true;
        for(int j = 0; j < arr.size(); j++){
            if(i%arr[j] != 0){
                b = false;
                break;
            }
        }
            if(b)
                return i;
    }
    return answer;
}