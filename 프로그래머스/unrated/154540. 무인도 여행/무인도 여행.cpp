#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;

int dfs(vector<string> maps, int pos_x, int pos_y, vector<vector<bool>>& visited, int count) {
    visited[pos_x][pos_y] = true;
    //좌
    if (pos_y >= 1 && maps[pos_x][pos_y - 1] != 'X'
        && !visited[pos_x][pos_y - 1]) {
        count += dfs(maps, pos_x, pos_y - 1, visited, maps[pos_x][pos_y - 1] - '0');
    }
    //우
    if (pos_y <= maps[0].size() - 2 && maps[pos_x][pos_y + 1] != 'X'
        && !visited[pos_x][pos_y + 1]) {
        count += dfs(maps, pos_x, pos_y + 1, visited, maps[pos_x][pos_y + 1] - '0');
    }
    //상
    if (pos_x >= 1 && maps[pos_x - 1][pos_y] != 'X'
        && !visited[pos_x - 1][pos_y]) {
        count += dfs(maps, pos_x - 1, pos_y, visited, maps[pos_x - 1][pos_y] - '0');
    }
    //하
    if (pos_x <= maps.size() - 2 && maps[pos_x + 1][pos_y] != 'X'
        && !visited[pos_x + 1][pos_y]) {
        count += dfs(maps, pos_x + 1, pos_y, visited, maps[pos_x + 1][pos_y] - '0');
    }
    return count;
}

vector<int> solution(vector<string> maps) {
    int count = 0;
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++)
            if (maps[i][j] != 'X' && visited[i][j] == false)
                answer.push_back(dfs(maps, i, j, visited, maps[i][j] - '0'));
    }
    if (answer.empty())
        answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}