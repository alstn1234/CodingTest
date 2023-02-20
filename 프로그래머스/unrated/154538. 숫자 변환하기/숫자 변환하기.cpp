#include <string>
#include <vector>

using namespace std;

vector<int> v(1000001, 0);
void dfs(int x, int y, int n, int cnt){
    if(y < x)
        return;
    
    if(x == y){
        if(v[y] == 0 || v[y] > cnt)
            v[y] = cnt+1;
        return;
    }
    
    if(v[x] > cnt+1 || v[x] == 0){
        if(x*2 > y){
            if((y-x)%n == 0)
                dfs(y, y, n, cnt+(y-x)/n);
            return;
        }
        v[x] = cnt+1;
        dfs(x+n, y, n, v[x]);
        dfs(x*3, y, n, v[x]);
        dfs(x*2, y, n, v[x]);
    }
    else
        return;
    
}

int solution(int x, int y, int n) {
    dfs(x, y, n, 0);
    return v[y]-1;
}