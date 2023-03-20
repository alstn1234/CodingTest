#include <string>
#include <vector>
#include <iostream>


using namespace std;


vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for(auto ball : balls){
        int pos = 2100000000;
        vector<int> dx;
        vector<int> dy;
        int x = ball[0], y = ball[1];
        
        if(ball[0] == startX){
            x = (startX > m/2) ? (m-ball[0])*2 : -ball[0]*2;
            dx.push_back(x); dy.push_back(0);
            y = (startY-ball[1] > 0) ? (n-ball[1])*2 : -ball[1]*2;
            dx.push_back(0); dy.push_back(y);
        }
        
        else if(ball[1] == startY){
            y = (startY > n/2) ? (n-ball[1])*2 : -ball[1]*2;
            dx.push_back(0); dy.push_back(y);
            x = (startX-ball[0] > 0) ? (m-ball[0])*2 : -ball[0]*2;
            dx.push_back(x); dy.push_back(0);
            
        }
        
        else{
            dx = {ball[0]*(-2), (m-ball[0])*2, 0, 0, ball[0]*(-2), 
                    ball[0]*(-2), (m-ball[0])*2, (m-ball[0])*2};
            dy = {0, 0, ball[1]*(-2), (n-ball[1])*2, ball[1]*(-2), 
                    (n-ball[1])*2, ball[1]*(-2), (n-ball[1])*2};
        }
        for(int i = 0 ; i < dx.size(); i++){
                x = ball[0]+dx[i];
                y = ball[1]+dy[i];
                pos = min(pos, (startX-x)*(startX-x)+(startY-y)*(startY-y));
            }
            answer.push_back(pos);
    }
    return answer;
}