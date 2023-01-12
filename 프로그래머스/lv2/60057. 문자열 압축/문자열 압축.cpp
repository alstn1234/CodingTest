#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
	string answer_str(s);
	int n = 1;
	while (n <= s.length() / 2) {
		int dev = s.length() % n;
		string str = "";
		int dev_n = s.length() / n;
		int cnt = 1;
		for (int i = 0; i < dev_n; i++) {
			string sub_s = s.substr(i * n, n);
			if (str == "")
				str = sub_s;
			else if (str.substr(str.length()-n,n) == sub_s)
				cnt++;
			else {
				if (cnt > 1)
					str += to_string(cnt);
				str += sub_s;
				cnt = 1;
				
			}
		}
		if(cnt > 1)
			str += to_string(cnt);
		if (dev != 0)
			str += s.substr(s.length() - dev, dev);
		if (answer_str.length() > str.length())
			answer_str = str;
		n++;
	}
	return answer_str.length();
}