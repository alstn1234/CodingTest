#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    priority_queue<int> pqA(A.begin(), A.end());
    priority_queue<int> pqB(B.begin(), B.end());
    
    while(!pqA.empty()){
        if(pqA.top() < pqB.top()){
            pqB.pop();
            answer++;
        }
        pqA.pop();
    }
    return answer;
}