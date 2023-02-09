#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char del){
    vector<string> answer;
    stringstream ss(input);
    string temp;
    
    while(getline(ss, temp, del)){
        answer.push_back(temp);
    }
    return answer;
}

string solution(string polynomial) {
    string answer = "";
    int coe = 0, con = 0;
    vector<string> v = split(polynomial, ' ');
    for(string s : v){
        if(s != "+"){
            if(s[s.length()-1] == 'x'){
                if(s.length() == 1)
                    coe++;
                else{
                    int n = stoi(s.substr(0,s.length()-1));
                    coe += n;
                }
            }
            else{
                con += stoi(s);
            }
        }
    }
    if(coe == 0)
        return to_string(con);
    if(con == 0){
        if(coe == 1)
            return "x";
        return to_string(coe) + "x";
    }
    if(coe == 1)
            return "x + " + to_string(con);;
    return to_string(coe) + "x + " + to_string(con);;
    
}