#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

bool solve(long n){
    if(n < 2)
        return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string s = "";
    while(n != 0){
        s += to_string(n%k);
        n /= k;
    }
    reverse(s.begin(), s.end());
    
    stringstream ss(s);
    string temp;
    while(getline(ss, temp, '0')){
        if(temp != ""){
            if(solve(stol(temp)))
                answer++;
        }
    }
    return answer;
}