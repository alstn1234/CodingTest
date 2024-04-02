#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, int k) {
    int answer = 0;
    for(int i = k; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            if(j < board.size() && i-j < board[0].size())
                answer += board[j][i-j];
        }
    }
    return answer;
}