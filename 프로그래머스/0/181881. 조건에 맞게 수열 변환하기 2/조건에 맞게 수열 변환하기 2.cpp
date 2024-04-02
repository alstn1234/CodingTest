#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    for(int x = 1; ; x++){
        int n = 0;
        for(int& e : arr){
            if(e >= 50 && e%2 == 0)
                e = e / 2;
            else if(e < 50 && e%2 == 1)
                e = e * 2 + 1;
            else
                n++;
        }
        if(n == arr.size())
            return x-1;
    }
    return answer;
}