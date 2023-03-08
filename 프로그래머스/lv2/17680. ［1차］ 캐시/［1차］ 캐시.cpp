#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    map<string, int> m;
    vector<string> v;
    for(auto city : cities){
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        
        if(m[city] > 0){
            answer += 1;
            m[city]--;
            v.erase(remove(v.begin(), v.end(), city), v.end());
        }
        else
            answer += 5;
        
        v.push_back(city);
        m[city]++;
        
        if(v.size() > cacheSize){
            m[v.front()]--;
            v.erase(v.begin());
        }
    }
    return answer;
}