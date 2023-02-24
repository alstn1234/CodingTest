#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int i = 0, j = 0;
    sort(X.rbegin(), X.rend());
    sort(Y.rbegin(), Y.rend());
    
    while(i != X.length() && j != Y.length()){
        if(X[i] == Y[j]){
            answer += X[i];
            i++; j++;
        }
        else if(X[i] > Y[j])
            i++;
        else
            j++;
    }
    if(answer == "")
        return "-1";
    if(answer[0] == '0')
        return "0";
    return answer;
}