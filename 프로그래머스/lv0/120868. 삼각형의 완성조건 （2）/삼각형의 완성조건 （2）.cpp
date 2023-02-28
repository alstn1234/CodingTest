#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    int big = max(sides[0], sides[1]);
    int small = min(sides[0], sides[1]);
    
    return 2*small-1;
}