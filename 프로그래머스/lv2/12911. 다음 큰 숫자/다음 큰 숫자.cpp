#include <string>
#include <vector>

using namespace std;

int binary(int n){
    int one = 0;
    while(n != 0){
        if(n%2==1)
            one++;
        n /= 2;
    }
    return one;
}

int solution(int n) {
    int answer = 0;
    int n_one = binary(n);
    for(int i = n + 1; true; i++){
        if(n_one == binary(i))
            return i;
    }
}