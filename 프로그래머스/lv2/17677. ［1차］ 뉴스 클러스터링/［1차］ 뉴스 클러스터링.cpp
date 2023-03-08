#include <string>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 1;
    vector<string> v1, v2;
    for(int i = 0; i < str1.length()-1; i++){
        string s = str1.substr(i, 2);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if(s[0] < 'a' || s[0] > 'z' || s[1] < 'a' || s[1] > 'z')
            continue;
        v1.push_back(s);
    }
    
    for(int i = 0; i < str2.length()-1; i++){
        string s = str2.substr(i, 2);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if(s[0] < 'a' || s[0] > 'z' || s[1] < 'a' || s[1] > 'z')
            continue;
        v2.push_back(s);
    }
    
    double d = v1.size()+v2.size();
    int e = 0;
    for(int i = 0; i < v1.size(); i++){
        for(int j = 0; j < v2.size(); j++){
            if(v1[i] == v2[j]){
                e++;
                v1.erase(v1.begin()+i--);
                v2.erase(v2.begin()+j--);
                break;
            }
        }
    }
    if(d > 0)
        answer = 65536/(d-e)*e;
    else
        answer = 65536;
    return answer;
}