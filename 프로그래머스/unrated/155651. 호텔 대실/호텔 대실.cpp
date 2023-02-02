#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int n = 0;
    int room_cnt = 0;
    vector<string> book;
    for(int i = 0; i < book_time.size(); i++){
        book.push_back(book_time[i][0] + 'B');  // B : CheckIn
        int h = stoi(book_time[i][1].substr(0,2));
        int m = stoi(book_time[i][1].substr(3,2));
        m += 10;
        if(m >= 60){
            m -= 60;
            h += 1;
        }
        string mm = to_string(m);
        string hh = to_string(h);
        if(h < 10)
            hh = '0' + to_string(h);
        if(m < 10)
            mm = '0' + to_string(m);
        book.push_back(hh + ':' + mm + 'A');  // A : CheckOut
    }
    priority_queue<string, vector<string>, greater<string>> pq(book.begin(), book.end());
    
    
    while(!pq.empty()){
        string time = pq.top();
        pq.pop();
        if(time[5] == 'B')
            room_cnt = max(room_cnt, ++n);
        else if(time[5] == 'A')
            n--;
    }
    return room_cnt;
}