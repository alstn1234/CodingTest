#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    while(!section.empty()){
        int p = section.back();
        section.pop_back();
        answer++;
        if(section.empty())
            break;
        while(p - section.back() < m && !section.empty())
            section.pop_back();
    }
    return answer;
}