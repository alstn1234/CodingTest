#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int n = 1;
    stack<int> assist;
    assist.push(-1);
    for(int i = 0; i < order.size(); i++){
        if(n > order[i] && assist.top() != order[i])
            break;
        while(n != order[i] && assist.top() != order[i]){
            assist.push(n);
            n++;
        }
        if(n == order[i])
            n++;
        
        else if(assist.top() == order[i])
            assist.pop();
        answer++;
    }
    return answer;
}