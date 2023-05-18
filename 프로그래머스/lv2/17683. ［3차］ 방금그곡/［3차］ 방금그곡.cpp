#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

vector<string> split(string input, char del){
    vector<string> answer;
    string temp;
    stringstream ss(input);
    
    while(getline(ss, temp, del)){
        answer.push_back(temp);
    }
    return answer;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    map<string, int> music_time;
    for(auto music : musicinfos){
        vector<string> v = split(music, ',');
        int hour = stoi(v[1].substr(0, 2)) - stoi(v[0].substr(0, 2));
        int minute = stoi(v[1].substr(3, 2)) - stoi(v[0].substr(3, 2));
        int time = hour*60+minute;
        
        string music_str = "";
        int now_time = 0; int n = 0;
        while(now_time < time){
            music_str += v[3][n++];
            if(n < v[3].size() && v[3][n] == '#')
                music_str += v[3][n++];
            if(n == v[3].size())
                n = 0;
            now_time++;
        }
        for(int i = 0; i <= 99999; i++){
            if(music_str[i] == '#')
                continue;
            string s = "";
            int index = i;
            while(s.length() < m.length()){
                if(index > music_str.length())
                    break;
                s += music_str[index++];
                if(music_str[index] == '#')
                    s += music_str[index++];
            }
            if(index > music_str.length())
                break;
            if(s == m){
                if(answer == "" || music_time[answer] < time){
                    music_time[v[2]] = time;
                    answer = v[2];  
                    break;
                }
            }
        }
    }
    return answer;
}