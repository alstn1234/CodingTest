#include <vector>

using namespace std;

int answer = -1;
vector<int> v({-1, 0, 1});
void dfs(vector<vector<int>> maps, int x, int y, int count){
    if(x == maps[0].size() - 1 && y == maps.size() - 1){
        answer = max(answer, count);
        return;
    }
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v.size(); j++){
            if(x + v[i] >= 0 && y + v[j] >= 0 && maps[x+v[i]][y+v[i]] == 1)
                dfs(maps, x + v[i], y + v[j], count + 1);
        }
    }
}

int solution(vector<vector<int> > maps)
{
    dfs(maps, 0, 0, 0);
    return answer;
}