#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for(int i = 0; i < array.size(); i++){
        for(int j = 100000; j > 0; j = j / 10){
            if((array[i] / j) == 7)
                answer++;
            array[i] %= j;
            
        }
    }
    return answer;
}