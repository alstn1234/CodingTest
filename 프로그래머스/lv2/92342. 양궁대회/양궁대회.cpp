#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;
vector<int> v;
int diff = 0;

void dfs(vector<int> info, int n, int k, int score){
    if(k == 0){
        v.push_back(n);
        if(score > 0){
            if(diff < score){
                answer = v;
                diff = score;
            }
            else if(diff == score){
                for(int i = 10; i >= 0; i--){
                    if(answer[i] < v[i]){
                        answer = v;
                        break;
                    }else if(answer[i] > v[i])
                        break;
                }
            }
        }
        v.pop_back();
        return;
    }
    if(info[k] < n){
        v.push_back(info[k]+1);
        dfs(info, n-info[k]-1, k-1, score+k);
        v.pop_back();
    }
    
    v.push_back(0);
    if(info[k] == 0)
        dfs(info, n, k-1, score);
    else
        dfs(info, n, k-1, score-k);
    v.pop_back();
}

vector<int> solution(int n, vector<int> info) {
    reverse(info.begin(), info.end());
    dfs(info, n, 10, 0);
    if(answer.size() == 0)
        answer.push_back(-1);
    return answer;
}