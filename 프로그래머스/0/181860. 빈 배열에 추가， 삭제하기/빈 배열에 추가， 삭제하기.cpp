#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;
    for(int i = 0; i < flag.size(); i++){
        for(int j = 0; j < arr[i]*2; j=j){
            if(flag[i]){
                answer.emplace_back(arr[i]);
                j++;
            }
            else{
                answer.pop_back();
                j += 2;
            }
        } 
    }
    return answer;
}