#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> check(int m, int n, vector<string> board){
    vector<pair<int, int>> del;
    for(int i = 0; i <= m-2; i++){
        for(int j = 0; j <= n-2; j++){
            if(board[i][j] != 'X' && (board[i][j] == board[i+1][j]) && (board[i][j] == board[i][j+1]) 
               && (board[i][j] == board[i+1][j+1])){
                del.push_back(pair<int, int>(i, j));
            }
        }
    }     
    return del;
}

vector<string> change(int m, int n, vector<string> board){
    for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(board[i][j] == 'X'){
                int k = i-1;
                while(k >= 0){
                    if(board[k][j] != 'X'){
                        board[i][j] = board[k][j];
                        board[k][j] = 'X';
                        break;
                    }
                    k--;
                }
            }
        }
    }
    return board;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<pair<int, int>> del;
    vector<int> dx = {0, 0, 1, 1};
    vector<int> dy = {0, 1, 0, 1};
    do{
        del.clear();
        del = check(m, n, board);
        //삭제
        for(auto d : del){
            for(int i = 0; i < dx.size(); i++){
                if(board[d.first+dx[i]][d.second+dy[i]] != 'X'){
                    board[d.first+dx[i]][d.second+dy[i]] = 'X';
                    answer++;
                }
            }
        }
        //수정
        board = change(m, n, board);
        
    }while(!del.empty());
    return answer;
}