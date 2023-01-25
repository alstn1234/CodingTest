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
    for(int i = 1; i < scores.size(); i++){
        if(inho[0] < scores[i][0] && inho[1] < scores[i][1])
            return -1;
        if(inho_total < scores[i][0] + scores[i][1]){
            for(int j = 1; j < scores.size(); j++){
                if(scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1])
                    break;
                if(j == scores.size() - 1)
                    score_total.push_back(scores[i][0] + scores[i][1]);
            }
        }
    }
    sort(score_total.rbegin(), score_total.rend());
    for(int i = 0; i < score_total.size(); i++){
        if(score_total[i] == inho_total)
            return i + 1;
    }
}