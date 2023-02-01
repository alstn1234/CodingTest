#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == 1){
                for(int a = i - 1; a <= i + 1; a++){
                    for(int b = j - 1; b <= j + 1; b++){
                        if (a >= 0 && a <= board.size() - 1 && b >= 0 && b <= board[0].size() 
                           && board[a][b] == 0){
                            board[a][b] = 2;
                        }
                    }
                }
            }
        }
    }for (auto n : board) {
        for (auto k : n) {
            if (k == 0)
                answer++;
        }
    }
    return answer;
}