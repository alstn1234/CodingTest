#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> m;
int sort_by_idx;

bool compare(vector<int> data1, vector<int> data2){
    return data1[sort_by_idx] < data2[sort_by_idx];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    m["code"] = 0; m["date"] = 1; m["maximum"] = 2; m["remain"] = 3;
    
    sort_by_idx = m[sort_by];
    int idx = m[ext];
    for(auto d : data){
        if(d[idx] < val_ext)
            answer.push_back(d);
    }
    
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}