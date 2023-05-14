#include <string>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    set<vector<int>> s;
    int x = 0, y = 0;
    
    for(char dir : dirs){
        vector<int> v;
        if(dir == 'U' && y+1 <= 5){
            y++; 
            v = {x, 6 , y-1, y};
        }
        if(dir == 'D' && y-1 >= -5){
            y--;
            v = {x, 6, y, y+1};
        }
        if(dir == 'R' && x+1 <= 5){
            x++;
            v = {x-1, x, 6, y};
        }
        if(dir == 'L' && x-1 >= -5){
            x--;
            v = {x, x+1, 6, y};
        }
        if(!v.empty())
            s.insert(v);
    }
    return s.size();
}