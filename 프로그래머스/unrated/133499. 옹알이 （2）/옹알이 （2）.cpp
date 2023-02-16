#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    for(string b : babbling){
        string k = b;
        string before_k = "";
        string before_word = "";
        while(k.length() != 0 && k != before_k){
            before_k = k;
            if(k[0] == 'a'){
                if(k.substr(0,3) != "aya" || before_word == "aya")
                    break;
                before_word = "aya";
                k = k.substr(3);
            }else if(k[0] == 'y'){
                if(k.substr(0,2) != "ye" || before_word == "ye")
                    break;
                before_word = "ye";
                k = k.substr(2);
            }else if(k[0] == 'w'){
                if(k.substr(0,3) != "woo" || before_word == "woo")
                    break;
                before_word = "woo";
                k = k.substr(3);
            }else if(k[0] == 'm'){
                if(k.substr(0,2) != "ma" || before_word == "ma")
                    break;
                before_word = "ma";
                k = k.substr(2);
            }
        }
        if(k.length() == 0)
            answer++;
    }
    return answer;
}