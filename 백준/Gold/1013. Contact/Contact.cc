#include <vector>
#include <iostream>
#include <regex>

using namespace std;

int main() {
    int test_num;

    cin >> test_num;
    for (int i = 0; i < test_num; i++) {
        string s;
        cin >> s;

        regex re("(100+1+|01)+");
        cout << (regex_match(s, re) ? "YES\n" : "NO\n");

    }

}