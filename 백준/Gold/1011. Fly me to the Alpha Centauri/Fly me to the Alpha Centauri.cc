#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int test_num;

    cin >> test_num;
    for (int i = 0; i < test_num; i++) {
        long long x, y;
        cin >> x >> y;

        long long move = 0;
        long long n = 1;
        while (n * n <= y - x) {
            n++;
        }
        move = (n - 1) * 2 - 1;
        long long remain = y - x - (n - 1) * (n - 1);
        long long m = (long long)ceil((double)remain / double(n - 1));
        cout << move + m << endl;
    }

}