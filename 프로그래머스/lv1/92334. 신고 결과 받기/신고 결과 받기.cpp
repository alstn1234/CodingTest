#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <map>

using namespace std;

vector<string> split(string input, char del) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, del)) {
        answer.push_back(temp);
    }
    return answer;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector<string> v;
    vector<set<string>> vs(id_list.size());
    map<string, int> m;

    for (auto re : report) {
        v = split(re, ' ');
        for (int i = 0; i < id_list.size(); i++) {
            if (id_list[i] == v[1]) {
                vs[i].insert(v[0]);
                break;
            }
        }
    }
    for (int i = 0; i < vs.size(); i++) {
        if (vs[i].size() >= k) {
            for (auto it = vs[i].begin(); it != vs[i].end(); it++) {
                m[*it]++;
            }
        }
    }
    for (auto id : id_list) {
        answer.push_back(0);
        for (auto it = m.begin(); it != m.end(); it++) {
            if (id == it->first) {
                answer.pop_back();
                answer.push_back(it->second);
                break;
            }
        }
    }
    return answer;
}
