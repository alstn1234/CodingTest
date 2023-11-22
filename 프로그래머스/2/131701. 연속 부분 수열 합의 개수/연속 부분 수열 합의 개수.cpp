#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    int size = elements.size();
    
    for(int i = 1; i <= size; i++){
        int k = 0;
        int sum = 0;
        for(int m = 0; m < size; m++){
            int p = i-1+k;
            for(int n = k; n <= p; n++){
                sum += elements[n%size];
            }
            s.insert(sum);
            sum = 0;
           k++;
        }
    }
    return s.size();
}