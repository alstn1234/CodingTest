#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    while(!babbling.empty()){
        string str = babbling.back();
        babbling.pop_back();
        for(int i = 0; i < str.length(); i++){
            bool check = false;
            switch(str[i]){
                case 'a':
                    if(str.substr(i+1,2) == "ya"){
                        i += 2;
                        check = true;
                    }
                    break;
                case 'y':
                    if(str.substr(i+1,1) == "e"){
                        i += 1;
                        check = true;
                    }
                    break;
                case 'w':
                    if(str.substr(i+1,2) == "oo"){
                        i += 2;
                        check = true;
                    }
                    break;
                case 'm':
                    if(str.substr(i+1,1) == "a"){
                        i += 1;
                        check = true;
                    }
                    break;
            }
            if(!check) break;
            if(i >= str.length()-1) answer++;
        }
    }
    return answer;
}