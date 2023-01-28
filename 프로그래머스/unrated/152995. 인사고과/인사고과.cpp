#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    int answer = 0;
    vector<int> inho = scores[0];
    int inho_total = inho[0] + inho[1];
    for(auto s : scores){
        if(inho[0] < s[0] && inho[1] < s[1])
            return -1;
        if(inho_total < s[0] + s[1]){
            for(int j = 1; j < scores.size(); j++){
                if(s[0] < scores[j][0] && s[1] < scores[j][1])
                    break;
                if(j == scores.size() - 1)
                    answer++;
            }
        }
    }
    return ++answer;
}