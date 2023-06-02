#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int, int>> v;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(pair<int, int>(num, i));
    }
    sort(v.begin(), v.end());

    vector<int> answer(n, 0);
    for (int i = 0; i < n; i++) {
        answer[v[i].second] = i;
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    
}