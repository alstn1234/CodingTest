#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<vector<char>> v = {{'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}};
    map<char, int> m;
    for(int i = 0; i < survey.size(); i++){
        if(choices[i] == 4)
            continue;
        else if(choices[i] < 4)
            m[survey[i][0]] += abs(choices[i]-4);
        else
            m[survey[i][1]] += abs(choices[i]-4);
    }
    for(auto vv : v){
        if(m[vv[0]] == m[vv[1]]){
            if(vv[0] >= vv[1])
                answer += vv[1];
            else
                answer += vv[0];
        }
        else if(m[vv[0]] > m[vv[1]])
            answer += vv[0];
        else
            answer += vv[1];
    }
    return answer;
}