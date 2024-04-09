#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
    auto idx = my_string.find(alp);
    while(idx != string::npos){
        my_string[idx] = toupper(my_string[idx]);
        idx = my_string.find(alp);
    }
    return my_string;
}