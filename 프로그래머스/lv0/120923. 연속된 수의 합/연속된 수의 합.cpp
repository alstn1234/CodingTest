#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    int i = 1;
    int cen = total / num;
    answer.push_back(cen);
    while(num > answer.size()){
        answer.push_back(cen + i);
        if(num == answer.size())
            break;
        answer.push_back(cen - i);
        i++;
    }
    sort(answer.begin(), answer.end());
    return answer;
}