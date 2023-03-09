#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    set<int> s;
    int i = 2;
    while(n != 1){
        while(n%i == 0){
            n /= i;
            s.insert(i);
        }
        i++;
    }
    for(auto ss : s)
        answer.push_back(ss);
    
    return answer;
}