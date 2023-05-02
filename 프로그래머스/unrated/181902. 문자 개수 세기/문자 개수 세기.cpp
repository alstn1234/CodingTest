#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52, 0);
    map<char, int> m;
    char c = 'A';
    
    for(int i = 0; i < 26; i++)
        m[c++] = i;
    
    c = 'a';
    for(int i = 26; i < 52; i++)
        m[c++] = i;
    
    for(int i = 0; i < my_string.size(); i++)
        answer[m[my_string[i]]]++;
    
    return answer;
}