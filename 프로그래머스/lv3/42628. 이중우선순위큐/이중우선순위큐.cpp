#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> v;
    reverse(operations.begin(), operations.end());

    while (!operations.empty()) {
        string str = operations.back();
        operations.pop_back();
        int num;
        switch (str[0]) {
        case 'I':
            num = stoi(str.substr(2));
            v.push_back(num);
            sort(v.rbegin(), v.rend()); //내림차순 정렬
            break;
        case 'D':
            num = stoi(str.substr(2));
            if (v.empty())
                break;
            if (num == 1)
                v.erase(v.begin());
            else
                v.erase(v.end()-1);
            break;
        }
    }
    if (v.empty())
        return { 0,0 };
    answer.push_back(v[0]);
    answer.push_back(v.back());
    return answer;
}