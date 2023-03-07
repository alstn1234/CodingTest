#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    k = 2*k-2;
    return numbers[k%numbers.size()];
}