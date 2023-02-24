#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    int cnt = 0, box_cnt = 0;
    int idx = 0, min_idx;
    vector<int> v;
    while(cnt != cards.size()){
        int temp = idx;
        idx = cards[temp]-1;
        cards[temp] = 0;
        cnt++; box_cnt++;
        if(cards[idx] == 0){
            v.push_back(box_cnt);
            box_cnt = 0;
            idx = 0;
            while(cards[idx] == 0)
                idx++;
        }
    }
    if(v.size() < 2)
        return 0;
    sort(v.rbegin(), v.rend());
    return v[0]*v[1];
}