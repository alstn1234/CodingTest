#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;
int num = 0;

void solve(int n, int x, int y){
    if(n <= 0)
        return;
    if(n == 1){
        v[x][y] = ++num;
        return;
    }
    for(int i = 0; i < n; i++){
        v[x+i][y] = ++num;
    }
    for(int i = 1; i < n; i++){
        v[x+n-1][y+i] = ++num;
    }
    for(int i = n-2; i > 0; i--){
        v[x+i][y+i] = ++num;
    }
    solve(n-3, x+2, y+1);
}

vector<int> solution(int n) {
    vector<int> answer;
    vector<int> k;
    for(int i = 0; i < n; i++){
        v.push_back(k);
        for(int j = 0; j <= i; j++){
            v[i].push_back(0);
        }
    }
    solve(n, 0, 0);
    for(auto vv : v){
        for(auto vvv : vv){
            answer.push_back(vvv);
        }
    }
    return answer;
}