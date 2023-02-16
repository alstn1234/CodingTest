#include <string>
#include <vector>

using namespace std;

long long solution(string numbers) {
    vector<string> v = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    for (int i = 0; i < v.size(); i++) {
        while (numbers.find(v[i]) != string::npos) {
            numbers.replace(numbers.find(v[i]), v[i].length(), to_string(i));
        }
    }

    return stoll(numbers);
}