#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	char c = 'z' + 1;
	string s, answer = "";
	answer += c;
	cin >> s;

	for (int i = 0; i < s.length() - 2; i++) {
		for (int j = i + 1; j < s.length() - 1; j++) {

			string s2;

			for (int m = i; m >= 0; m--) 
				s2 += s[m];
			for (int m = j; m > i; m--)
				s2 += s[m];
			for (int m = s.length() - 1; m > j; m--)
				s2 += s[m];
			answer = answer > s2 ? s2 : answer;
		}
	}
	cout << answer;
}