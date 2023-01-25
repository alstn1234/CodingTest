#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_l = max(sizes[0][0],sizes[0][1]);
    int min_l = min(sizes[0][0],sizes[0][1]);
    for(int i = 0; i < sizes.size(); i++){
        if(max_l < max(sizes[i][0], sizes[i][1]))
            max_l = max(sizes[i][0], sizes[i][1]);
        if(min_l < min(sizes[i][0], sizes[i][1]))
            min_l = min(sizes[i][0], sizes[i][1]);
    }
    return max_l * min_l;
}