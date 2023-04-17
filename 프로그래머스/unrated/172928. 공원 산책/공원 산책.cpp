#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    pair<int, int> pos = {-1, -1};
    int width = park[0].size(), height = park.size();
    // 시작 위치 찾기
    for(int i = 0; i < park.size(); i++){
        for(int j = 0; j < park[0].size(); j++){
            if(park[i][j] == 'S'){
                pos = {i, j};
                break;
            }
            if(pos.first != -1)
                break;
        }
    }
    
    for(string route : routes){
        int move = (route[2] - '0');
        if(route[0] == 'N'){  // 북
            if(pos.first - move < 0)
                continue;
            for(int i = pos.first-1; i >= pos.first - move; i--){
                if(park[i][pos.second] == 'X'){
                    pos.first += move;
                    break;
                }
            }
            pos.first -= move;
        }
        if(route[0] == 'S'){  // 남
            if(pos.first + move >= height)
                continue;
            for(int i = pos.first+1; i <= pos.first + move; i++){
                if(park[i][pos.second] == 'X'){
                    pos.first -= move;
                    break;
                }
            }
            pos.first += move;
        }
        if(route[0] == 'W'){  // 서
            if(pos.second - move < 0)
                continue;
            for(int i = pos.second-1; i >= pos.second - move; i--){
                if(park[pos.first][i] == 'X'){
                    pos.second += move;
                    break;
                }
            }
            pos.second -= move;
        }
        if(route[0] == 'E'){  // 동
            if(pos.second + move >= width)
                continue;
            for(int i = pos.second+1; i <= pos.second + move; i++){
                if(park[pos.first][i] == 'X'){
                    pos.second -= move;
                    break;
                }
            }
            pos.second += move;
        }
    }
    answer.push_back(pos.first);
    answer.push_back(pos.second);
    return answer;
}