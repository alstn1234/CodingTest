#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array) {
    int max_value = *max_element(array.begin(), array.end());
    for(int i = 0; i < array.size(); i++){
        if(max_value == array[i])
            return {array[i], i};
    }
}