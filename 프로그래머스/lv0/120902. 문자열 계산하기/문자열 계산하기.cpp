#include <string>
#include <vector>
#include <sstream>
#include <queue>

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

int solution(string my_string) {
    int answer = 0;
    vector<string> v = split(my_string, ' ');
    queue<string> q;
    for(string vv : v)
        q.push(vv);
    answer = stoi(q.front());
    q.pop();
    while(!q.empty()){
        string a = q.front();
        q.pop();
        if(a == "+"){
            answer += stoi(q.front());
            q.pop();
        }
        if(a == "-"){
            answer -= stoi(q.front());
            q.pop();
        }
    }
    return answer;
}