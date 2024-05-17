#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> table;
    int time = 540 - t;
    int lastShuttle = time + t*n;
    for(auto time : timetable){
        int t = stoi(time.substr(0, 2))*60 + stoi(time.substr(3, 5));
        table.push_back(t);
    }
    sort(table.rbegin(), table.rend());

    for(int i = 0; i < n; i++){
        time += t;
        for(int j = 0; j < m; j++){
            if(table.size() == 0){
                time = lastShuttle;
                break;
            } 
            if(table.back() > time){
                break;
            }
            if(table.back() <= time){
                if(i == n-1 && j == m-1)
                    time = table.back() -1;
                table.pop_back();
                continue;
            }
        }
    }
    
    string hour = to_string(time / 60); 
    string min = to_string(time % 60);
    if(hour.size() < 2) hour = "0" + hour;
    if(min.size() < 2) min = "0" + min;
    return hour +":"+min;
}