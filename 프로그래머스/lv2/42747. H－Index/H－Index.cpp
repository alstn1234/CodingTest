#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.rbegin(), citations.rend());
    if(citations[0] == citations.back())
        return 0;
    for(int j = citations[0]; j > 0; j--){
        for(int i = 0; i < citations.size(); i++){
            if(citations[i] < j){
                if(i >= j && citations.size() - i <= j){
                    return j;
                }
                break;
            }
        }
    }
    return citations.size();
}