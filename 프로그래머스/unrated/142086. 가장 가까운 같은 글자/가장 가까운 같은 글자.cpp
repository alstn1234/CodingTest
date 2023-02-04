#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(s.length(), -1);
    for(char i = 'a'; i <= 'z'; i++){
        bool is_al = false;
        int count = 0;
        for(int j = 0; j < s.length(); j++){
            count++;
            if(i == s[j]){
                if(!is_al)
                    is_al = true;
                else
                    answer[j] = count;
                count = 0;
            }
        }
    }
    return answer;
}