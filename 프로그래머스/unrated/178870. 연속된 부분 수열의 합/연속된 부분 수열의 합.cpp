#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int n = sequence.size()-1, idx = 0, sum = 0;
    while(true){
        sum += sequence[n-idx];
        if(sum == k){
            while(sequence[n] == sequence[n-idx-1])
                n--;
            answer.push_back(n-idx);
            answer.push_back(n);
            break;
        }
        else if(sum > k){
            sum -= sequence[n];
            n--;
        }
        else
            idx++;
    }
    
    return answer;
}