#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> board(rows+1, vector<int>(columns+1, 0));
    int k = 1;
    for(int i = 1; i < rows+1; i++){
        for(int j = 1; j < columns+1; j++){
            board[i][j] = k++;
        }
    }
    for(auto q : queries){
        int n = rows*columns;
        int x = q[0], y = q[1];
        int now = board[q[0]][q[1]];
        int next;
        n = min(n, now);
        while(y != q[3]){
            n = min(n, now);
            next = board[x][++y];
            board[x][y] = now;
            now = next;
        }
        
        n = min(n, now);
        while(x != q[2]){
            n = min(n, now);
            next = board[++x][y];
            board[x][y] = now;
            now = next;
        }
        
        n = min(n, now);
        while(y != q[1]){
            n = min(n, now);
            next = board[x][--y];
            board[x][y] = now;
            now = next;
        }
        
        n = min(n, now);
        while(x != q[0]){
            n = min(n, now);
            next = board[--x][y];
            board[x][y] = now;
            now = next;
        }
        answer.push_back(n);
    }
    return answer;
}