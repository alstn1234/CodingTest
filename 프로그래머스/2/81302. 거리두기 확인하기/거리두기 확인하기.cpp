#include <string>
#include <vector>

using namespace std;

bool solve(vector<string> place, int x, int y){
    if((x-1 >= 0 && place[x-1][y] == 'P') || (x+1 <= 4 && place[x+1][y] == 'P') ||
      (y-1 >= 0 && place[x][y-1] == 'P') || (y+1 <= 4 && place[x][y+1] == 'P') ||
      (x-2 >= 0 && place[x-2][y] == 'P' && place[x-1][y] != 'X') || 
      (x+2 <= 4 && place[x+2][y] == 'P' && place[x+1][y] != 'X') ||
      (y-2 >= 0 && place[x][y-2] == 'P' && place[x][y-1] != 'X') ||
      (y+2 <= 4 && place[x][y+2] == 'P' && place[x][y+1] != 'X') ||
      (x+1 <= 4 && y+1 <= 4 && place[x+1][y+1] == 'P' && (place[x][y+1] != 'X' || place[x+1][y] != 'X')) ||
      (x+1 <= 4 && y-1 >= 0 && place[x+1][y-1] == 'P' && (place[x][y-1] != 'X' || place[x+1][y] != 'X')) ||
      (x-1 >= 0 && y+1 <= 4 && place[x-1][y+1] == 'P' && (place[x][y+1] != 'X' || place[x-1][y] != 'X')) ||
      (x-1 >= 0 && y-1 >= 0 && place[x-1][y-1] == 'P' && (place[x][y-1] != 'X' || place[x-1][y] != 'X')))
        return true;
    
    
    return false;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto p : places){
        bool b = false;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(p[i][j] == 'P'){
                    if(solve(p, i, j)){
                        b = true;
                        break;
                    }
                }
            }
            if(b)
                break;
        }
        if(!b)
            answer.push_back(1);
        else
            answer.push_back(0);
            
    }
    return answer;
}