#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> sides) {
    sort(sides.begin(), sides.end());
    int answer = (sides[0] + sides[1] > sides[2]) ? 1 : 2;
    return answer;
}