#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int n = 0;
    int room_cnt = 0;
    vector<pair<int, char>> book;
    for(int i = 0; i < book_time.size(); i++){
        int h = stoi(book_time[i][0].substr(0,2));
        int m = stoi(book_time[i][0].substr(3,2));
        book.push_back(pair<int, char>(h*60+m, 'B'));  // B : CheckIn
        
        h = stoi(book_time[i][1].substr(0,2));
        m = stoi(book_time[i][1].substr(3,2));
        book.push_back(pair<int, char>(h*60+m+10, 'A'));  // A : CheckOut
    }
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq(book.begin(), book.end());
    
    
    while(!pq.empty()){
        auto time = pq.top();
        pq.pop();
        if(time.second == 'B')
            room_cnt = max(room_cnt, ++n);
        else if(time.second == 'A')
            n--;
    }
    return room_cnt;
}