#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 0;
    vector<int> score_total;
    vector<int> inho = scores[0];
    int inho_total = inho[0] + inho[1];
    score_total.push_back(inho_total);
    for(auto s : scores){
        if(inho[0] < s[0] && inho[1] < s[1])
            return -1;
        if(inho_total < s[0] + s[1]){
            for(int j = 1; j < scores.size(); j++){
                if(s[0] < scores[j][0] && s[1] < scores[j][1])
                    break;
                if(j == scores.size() - 1)
                    score_total.push_back(s[0] + s[1]);
            }
        }
    }
    sort(score_total.rbegin(), score_total.rend());
    for(int i = 0; i < score_total.size(); i++)
        if(score_total[i] == inho_total)
            return i + 1;
}