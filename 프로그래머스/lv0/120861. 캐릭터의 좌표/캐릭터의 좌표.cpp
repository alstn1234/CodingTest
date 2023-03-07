#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    int x = 0, y = 0;
    for(string k : keyinput){
        if(k == "left" && x > -board[0]/2) x--;
        if(k == "right" && x < board[0]/2) x++;
        if(k == "down"&& y > -board[1]/2) y--;
        if(k == "up" && y < board[1]/2) y++;
    }
    return {x,y};
}