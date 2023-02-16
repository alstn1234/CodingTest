#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    int m = 100;
    for(int arr : array){
        if(m > abs(arr-n)){
            answer = arr;
            m = abs(arr-n);
        }
        else if(m == abs(arr-n))
            if(arr < answer)
                answer = arr;
    }
    return answer;
}