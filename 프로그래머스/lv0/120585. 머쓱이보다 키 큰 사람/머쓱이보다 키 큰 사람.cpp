#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;
    for(int i : array)
        answer = (i > height) ? answer+1 : answer;
    return answer;
}