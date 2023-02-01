#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = -1;
    int max_cnt = 0;
    int cnt = 1;
    sort(array.begin(), array.end());
    if(array.size() == 1)
        return array[0];
    for(int i = 1; i < array.size(); i++){
        if(array[i] == array[i - 1])
            cnt++;
        else
            cnt = 1;
        if(max_cnt < cnt)
            max_cnt = cnt;
    }
    cnt = 1;
    for(int i = 1; i < array.size(); i++){
        if(array[i] == array[i - 1])
            cnt++;
        else{
            cnt = 1;
        }
        if(max_cnt == cnt){
            if(answer != -1)
                return -1;
            answer = array[i];
        }
    }
    return answer;
}