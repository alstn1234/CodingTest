#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.rbegin(), citations.rend());
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
    if(citations[0] < citations.size())
        return 0;
    return citations.size();
}