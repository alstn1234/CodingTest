#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int size = queue1.size() + queue2.size();
    long q1 = accumulate(queue1.begin(), queue1.end(), 0);
    long q2 = accumulate(queue2.begin(), queue2.end(), 0);
    int cnt = 0;
    int i = 0, j = 0;
    
    while(q1 != q2){
        while(q1 > q2){
            q1 -= queue1[i];
            q2 += queue1[i];
            queue2.push_back(queue1[i++]);
            cnt++; answer++;
        }
        while(q1 < q2){
            q2 -= queue2[j];
            q1 += queue2[j];
            queue1.push_back(queue2[j++]);
            cnt++; answer++;
        }
        if(cnt > size*2)
            return -1;
    }
    return answer;
}