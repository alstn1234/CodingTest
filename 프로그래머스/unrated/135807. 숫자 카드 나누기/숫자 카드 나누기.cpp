#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int min_A = *min_element(arrayA.begin(), arrayA.end());
    int min_B = *min_element(arrayB.begin(), arrayB.end());
    
    for(int i = 1; i <= min_A; i++){
        for(int j = 0; j < arrayA.size(); j++){
            if(arrayA[j] % i != 0 || arrayB[j] % i == 0)
                break;
            if(j == arrayA.size() - 1)
                answer = max(answer, i);
        }
    }
    
    for(int i = 1; i <= min_B; i++){
        for(int j = 0; j < arrayB.size(); j++){
            if(arrayB[j] % i != 0 || arrayA[j] % i == 0)
                break;
            if(j == arrayB.size() - 1)
                answer = max(answer, i);
        }
    }
    return answer;
}