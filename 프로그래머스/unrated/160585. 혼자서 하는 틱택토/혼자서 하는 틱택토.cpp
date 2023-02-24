#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1 };
vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1 };

bool solve(vector<string> board, char c){
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] != c)
                continue;
            for(int m = 0; m < dx.size(); m++){
                int x = i+dx[m], y = j+dy[m];
                if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
                    continue;
                if(board[x][y] == c){
                    x += dx[m]; y += dy[m];
                    if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
                        continue;
                    if(board[x][y] == c)
                        return true;
                }
            }
        }
    }
    return false;
}

int solution(vector<string> board) {
    int o = 0, x = 0;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == 'O'){
                o++;
            }
            if(board[i][j] == 'X'){
                x++;
            }
        }
    }
    bool ob = solve(board, 'O');
    bool xb = solve(board, 'X');
    
    cout << ob << xb << endl;
    /*if((!xb && ob && o-x==1) || (!ob && xb && o==x) || 
       (!ob && !xb && (o-x==1 || o-x==0)))
        return 1;*/
    if((o-x!=1 && o-x!=0) || (ob && xb) || (ob && o<=x) || (xb && o>x))
        return 0;
    return 1;
}