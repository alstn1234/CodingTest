#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        while (answer % 3 == 0 || (answer % 10) == 3 || (answer / 10) == 3 || (answer % 100) / 10 == 3  )
            answer++;
        answer++;
    }


    return answer - 1;
}
