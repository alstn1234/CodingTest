#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    if(str1.find(str2) != std::string::npos)
        return 1;
    return 2;
}