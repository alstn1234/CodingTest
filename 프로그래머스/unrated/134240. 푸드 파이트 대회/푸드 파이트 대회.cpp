#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for(int i = 1; i < food.size(); i++){
        for(int j = 1; j <= food[i]/2; j++){
            answer += to_string(i);
        }
    }
    string a = answer;
    reverse(answer.begin(), answer.end());
    return a + '0' + answer;
}