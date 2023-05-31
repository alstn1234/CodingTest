#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    int size = arr.size() - arr[0].size();
    if(size > 0){
        for(auto& a : arr){
            for(int i = 0; i < size; i++)
                a.push_back(0);
        }
    }
    else{
        vector<int> v(arr[0].size(), 0);
        for(int i = 0; i < -size; i++)
            arr.push_back(v);
    }
    return arr;
}