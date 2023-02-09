#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer(score.size(), 0);
    vector<int> v;
    for(int i = 0; i < score.size(); i++)
        v.push_back(score[i][0]+score[i][1]);
    
    sort(v.rbegin(), v.rend());
    for(int j = 0; j < v.size(); j++){
        for(int i = 0; i < score.size(); i++){
            if(score[i][0]+score[i][1] == v[j])
                if(answer[i] == 0)
                    answer[i] = j+1;
        }
    }
    return answer;
}