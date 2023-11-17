#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int _n;

bool compare(string str1, string str2){
    if(str1[_n] > str2[_n])
        return false;
    else if(str1[_n] == str2[_n])
        return str1 < str2;
    return true;
}

vector<string> solution(vector<string> strings, int n) {
    _n = n;
    sort(strings.begin(), strings.end(), compare);
    return strings;
}