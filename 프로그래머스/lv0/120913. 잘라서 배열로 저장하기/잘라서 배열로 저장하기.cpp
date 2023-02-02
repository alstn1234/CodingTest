#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    for(int i = 0; i < (my_str.length() - 1) / n + 1; i++){
        answer.push_back(my_str.substr(i*n, n));
    }
    return answer;
}