#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> v1, vector<int> v2){
    if(v1[1] == v2[1])
        return v1[0] < v2[0];
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), cmp);
    int cameraPos = -30001;
    for(auto route : routes){
        if(cameraPos < route[0]){
            cameraPos = route[1];
            answer++;
        }
    }
    return answer;
}