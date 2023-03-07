#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int s_x = wallpaper.size()-1, b_x = 0;
    int s_y = wallpaper[0].size()-1, b_y = 0;
    
    for(int i = 0; i < wallpaper.size(); i++){
        for(int j = 0; j < wallpaper[0].size(); j++){
            if(wallpaper[i][j] == '#'){
                s_x = min(i, s_x); b_x = max(i, b_x);
                s_y = min(j, s_y); b_y = max(j, b_y);
            }
        }
    }
    answer.push_back(s_x);
    answer.push_back(s_y);
    answer.push_back(b_x+1);
    answer.push_back(b_y+1);
    return answer;
}