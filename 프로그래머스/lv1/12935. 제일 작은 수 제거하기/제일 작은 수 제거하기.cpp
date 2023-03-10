#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    int small = *min_element(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++)
        if(small == arr[i])
            arr.erase(arr.begin()+i);
    
    return (arr.empty()) ? vector<int>(1, -1) : arr;
}