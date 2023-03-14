#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int s = land.size()-1;
    for(int i = 1; i < land.size(); i++){
        land[i][0] += max(max(land[i-1][1], land[i-1][2]), land[i-1][3]);
        land[i][1] += max(max(land[i-1][0], land[i-1][2]), land[i-1][3]);
        land[i][2] += max(max(land[i-1][1], land[i-1][0]), land[i-1][3]);
        land[i][3] += max(max(land[i-1][1], land[i-1][2]), land[i-1][0]);
    }
    
    return max(max(max(land[s][0], land[s][1]), land[s][2]), land[s][3]);
}