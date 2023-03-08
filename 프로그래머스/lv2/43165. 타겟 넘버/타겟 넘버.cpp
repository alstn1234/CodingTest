#include <string>
#include <vector>

using namespace std;
int answer = 0;

void dfs(int i, int n, vector<int> numbers, int target){
    i++;
    if(i == numbers.size()){
        if(n == target)
            answer++;
        return;
    }
    dfs(i, n+numbers[i], numbers, target);
    dfs(i, n-numbers[i], numbers, target);
}

int solution(vector<int> numbers, int target) {
    dfs(-1, 0, numbers, target);
    return answer;
}