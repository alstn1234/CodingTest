#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> m;
    set<int> a;
    set<int> b;
    a.insert(topping[0]);
    
    for(int i = 1; i < topping.size(); i++){
        m[topping[i]]++;
        b.insert(topping[i]);
    } 
    
    for(int i = 1; i < topping.size(); i++){
        m[topping[i]]--;
        a.insert(topping[i]);
        if(m[topping[i]] == 0)
            b.erase(topping[i]);
        if(a.size() == b.size())
            answer++;
    } 
    return answer;
}