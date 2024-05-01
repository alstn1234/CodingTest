#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> v1, vector<int> v2){
    return v1[2] < v2[2];
}

int GetParent(vector<int> parent, int child){
    if(parent[child] == child) return child;
    return GetParent(parent, parent[child]);
}

void UnionParent(vector<int>& parent, int child1, int child2){
    child1 = GetParent(parent, child1);
    child2 = GetParent(parent, child2);
    if(child1 < child2) parent[child2] = child1;
    else parent[child1] = child2;
}

bool CheckParent(vector<int> parent, int child1, int child2){
    child1 = GetParent(parent, child1);
    child2 = GetParent(parent, child2);
    if(child1 == child2) return true;
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> parent(n, 0);
    for(int i = 0; i < n; i++) parent[i] = i;
    sort(costs.begin(), costs.end(), cmp);
    
    for(auto cost : costs){
        if(!CheckParent(parent, cost[0], cost[1])){
            answer += cost[2];
            UnionParent(parent, cost[0], cost[1]);
        }
    }
    return answer;
}