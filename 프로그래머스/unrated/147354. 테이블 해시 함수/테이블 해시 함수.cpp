#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int c;
bool compare(vector<int> i, vector<int> j){
    if(i[c] == j[c])
        return i[0] > j[0];
    return i[c] < j[c];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    c = col - 1;
    sort(data.begin(), data.end(), compare);
    for(auto d : data){
       // cout << d[0] << d[1] << d[2] << endl;
    }
    for(int i = row_begin-1; i <= row_end-1; i++){
        int sum = 0;
        for(int j = 0; j < data[i].size(); j++){
            sum += data[i][j]%(i+1);
            //cout << data[i][j] << " " << i+1 << endl;
        }
        answer= answer^sum;
    }
    return answer;
}