#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solve(long long n){
    if(n == 0)
        return 1;
    string s = "";
    long long nn = n;
    while(nn != 0){
        s += nn%2 + '0';
        nn /= 2;
    }
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            if(i == 0)
                return n+pow(2, i);
            else
                return n+pow(2, i-1);
        }
    }
    return n+pow(2, s.size()-1);
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i = 0; i < numbers.size(); i++)
        answer.push_back(solve(numbers[i]));
    return answer;
}