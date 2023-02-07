#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    int answer = a.size();
    int min_a;
    int n = *min_element(a.begin(), a.end());
    
    min_a = a.front();
    if(min_a != n){
        for(int i = 1; a[i]!=n; i++){
            if(min_a < a[i])
                answer--;
            else
            min_a = a[i];
        }
    }
    
    min_a = a.back();
    if(min_a != n){
        for(int i = a.size()-2; a[i]!=n; i--){
            if(min_a < a[i])
                answer--;
            else
                min_a = a[i];
        }
    }
    return answer;
}