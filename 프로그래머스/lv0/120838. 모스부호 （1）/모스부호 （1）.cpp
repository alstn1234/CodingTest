#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char c){
    vector<string> answer;
    stringstream ss(input);
    string temp;
    
    while(getline(ss, temp, c))
        answer.push_back(temp);
    return answer;
}

string solution(string letter) {
    string answer = "";
    vector<pair<string, string>> v = 
    { {".-","a"},{"-...","b"},{"-.-.","c"},{"-..","d"},{".","e"},{"..-.","f"},
    {"--.","g"},{"....","h"},{"..","i"},{".---","j"},{"-.-","k"},{".-..","l"},
    {"--","m"},{"-.","n"},{"---","o"},{".--.","p"},{"--.-","q"},{".-.","r"},
    {"...","s"},{"-","t"},{"..-","u"},{"...-","v"},{".--","w"},{"-..-","x"},
    {"-.--","y"},{"--..","z"}};
    vector<string> l = split(letter, ' ');
    for(auto m : l){
        for(auto vv : v){
            if(m == vv.first){
                answer += vv.second;
                break;
            }
        }
    }
    return answer;
}