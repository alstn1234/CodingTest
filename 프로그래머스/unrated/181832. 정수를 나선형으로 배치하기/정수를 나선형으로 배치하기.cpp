#include <string>
#include <vector>

using namespace std;

vector<int> dx = { 0, 1, 0, -1 };
vector<int> dy = { 1, 0, -1, 0 };

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    vector<vector<int>> v;
    int i = 2, idx = 0;
    int col = 0, row = 0;
    answer[0][0] = 1;

    while (i <= n * n) {
        while (row + dx[idx] >= 0 && row + dx[idx] < n && col + dy[idx] >= 0 &&
            col + dy[idx] < n && answer[row + dx[idx]][col + dy[idx]] == 0) {
            row += dx[idx]; col += dy[idx];
            answer[row][col] = i++;
        }
        if (++idx == 4) 
            idx = 0;
    }

    return answer;
}