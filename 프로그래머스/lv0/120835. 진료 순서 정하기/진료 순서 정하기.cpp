#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    vector<int> e = emergency;
    sort(e.rbegin(), e.rend());
    for(auto n : emergency){
        for(int i = 0; i < e.size(); i++){
            if(n == e[i])
                answer.push_back(i+1);
        }
    }
    return answer;
}