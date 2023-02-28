#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    for(int i = 0; i < my_string.length(); i++){
        string num = "";
        while(my_string[i] >= '0' && my_string[i] <= '9')
            num += my_string[i++];
        if(num != "")
            answer += stoi(num);
    }
    return answer;
}