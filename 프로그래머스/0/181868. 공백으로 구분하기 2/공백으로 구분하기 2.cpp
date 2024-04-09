#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string stringBuffer;
    stringstream ss(my_string);
    while(getline(ss, stringBuffer, ' ')){
        if(stringBuffer != "")
            answer.push_back(stringBuffer);
    }
    return answer;
}