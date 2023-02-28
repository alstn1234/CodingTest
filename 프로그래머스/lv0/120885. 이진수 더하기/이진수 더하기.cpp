#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string bin1, string bin2) {
    if(bin1 == "0" && bin2 == "0")
        return "0";
    string answer = "";
    long long n = stoll(bin1) + stoll(bin2);
    int carry = 0;
    while (n != 0 || carry != 0) {
        long long num = n % 10 + carry;
        answer += to_string(num%2);
        carry = num/2;
        n /= 10;
    }
    reverse(answer.begin(), answer.end());
    return  answer;
}