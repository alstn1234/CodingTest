#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<stack<int>> s;
    stack<int> n;
    n.push(1);
    for(int ingre : ingredient){
        if(s.empty()){
            if(ingre == 1)
                s.push(n);
        }
        else if(ingre == 1){
            if(s.top().top() == 3){
                answer++;
                s.pop();
            }
            else
                s.push(n);
        }
        else if(ingre == 2){
            if(s.top().top() == 1)
                s.top().push(2);
            else
                while(!s.empty())
                    s.pop();
        }
        else if(ingre == 3){
            if(s.top().top() == 2)
                s.top().push(3);
            else
                while(!s.empty())
                    s.pop();
        }
    }
    return answer;
}