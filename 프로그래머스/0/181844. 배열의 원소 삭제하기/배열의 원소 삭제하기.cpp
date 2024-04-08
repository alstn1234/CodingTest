#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    for(auto d : delete_list){
        auto itr = find(arr.begin(), arr.end(), d);
        if(itr != arr.end())
            arr.erase(itr);
    }
    return arr;
}