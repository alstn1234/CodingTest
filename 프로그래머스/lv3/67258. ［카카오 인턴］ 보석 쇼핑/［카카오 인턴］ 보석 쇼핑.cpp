#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    set<string> s(gems.begin(), gems.end());
    int size = s.size();
    int min = 100000;
    int v_min = 1;
    multiset<int> v;
    map<string, int> m;
    
    if(size == 1)
        return {1, 1};
    
    for(int i = 0; i < gems.size(); i++){
        if(m.find(gems[i]) != m.end()){
            int a = m[gems[i]];
            v.erase(a);
        }
        m[gems[i]] = i + 1;
        v.insert(i + 1);
        if(m.size() == size){
            auto iter = v.begin();
            v_min = *iter;
            if(min > (i+1)-v_min){
                answer[0] = v_min;
                answer[1] = i+1;
                min = (i+1)-v_min;
            }
        }
    }
    return answer;
}