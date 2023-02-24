#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer = {0, 0};
    for(auto l : lottos){
        if(l == 0)
                answer[0]++;
        for(auto win : win_nums){
            if(win == l){
                answer[0]++; answer[1]++;
            }
        }
    }
    answer[0] = (abs(answer[0] - 7) == 7) ? 6 : abs(answer[0] - 7);
    answer[1] = (abs(answer[1] - 7) == 7) ? 6 : abs(answer[1] - 7);

    return answer;
}