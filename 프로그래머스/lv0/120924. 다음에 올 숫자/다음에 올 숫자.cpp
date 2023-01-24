#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = ((common[1]*2-common[0]) == common[2]) ? common[common.size()-1] + common[1] - common[0] :
    common[common.size()-1]*(common[1]/common[0]);
    return answer;
}