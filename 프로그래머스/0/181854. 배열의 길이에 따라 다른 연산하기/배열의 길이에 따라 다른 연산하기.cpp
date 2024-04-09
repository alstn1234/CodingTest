#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    int idx = arr.size()%2 ? 0 : 1;
    for(idx; idx < arr.size(); idx+=2)
        arr[idx] += n;
    return arr;
}