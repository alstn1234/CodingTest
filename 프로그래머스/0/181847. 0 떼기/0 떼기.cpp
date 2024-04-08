#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    string answer = "";
    int n = 0;
    for(n; n < n_str.length(); n++){
        if(n_str[n] != '0') break;
    }
    return n_str.substr(n);
}