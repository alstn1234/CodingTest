#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    for(int i = 0; i < strArr.size(); i += 2){
        for(auto& str : strArr[i])
            str = tolower(str);
    }
    for(int i = 1; i < strArr.size(); i += 2){
        for(auto& str : strArr[i])
            str = toupper(str);
    }
    
    return strArr;
}