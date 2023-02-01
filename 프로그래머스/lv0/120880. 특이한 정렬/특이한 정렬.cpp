#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    int idx;
    int min_value = 9999;
    sort(numlist.begin(), numlist.end());
    for(int i = 0; i < numlist.size(); i++){
        if(numlist[i] == n){
            idx = i;
            break;
        }
        if(numlist[i] > n && (numlist[i] - n < min_value)){
            min_value = numlist[i] - n;
            idx = i;
        }
        if(numlist[i] < n && (n - numlist[i] < min_value)){
            min_value = n - numlist[i];
            idx = i;
        }
    }
    
    int min_idx = idx - 1;
    int max_idx = idx + 1;
    answer.push_back(numlist[idx]);
    while(min_idx != -1 && max_idx != numlist.size()){
        if(n - numlist[min_idx] >= numlist[max_idx] - n)
            answer.push_back(numlist[max_idx++]);
        else if(n - numlist[min_idx] < numlist[max_idx] - n)
            answer.push_back(numlist[min_idx--]);
        
    }
    while(min_idx != -1)
        answer.push_back(numlist[min_idx--]);
    while(max_idx != numlist.size())
        answer.push_back(numlist[max_idx++]);
    
    
    return answer;
}