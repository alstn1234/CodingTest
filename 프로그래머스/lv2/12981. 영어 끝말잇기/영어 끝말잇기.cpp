#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    map<string, bool> m;
    char before_c = words[0][words[0].length()-1];
    m[words[0]] = true;
    for(int i = 1; i < words.size(); i++){
        cout << words[i] << endl;
        if(m.find(words[i]) != m.end() || before_c != words[i][0]){
            answer[0] = (i)%n+1;
            answer[1] = (i)/n+1;
            break;
        }
        else{
            m[words[i]] = true;
            before_c = words[i][words[i].length()-1];
        }
        
    }
    

    return answer;
}