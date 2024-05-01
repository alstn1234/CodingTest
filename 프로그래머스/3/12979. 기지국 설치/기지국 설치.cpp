#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int size = stations.size() - 1;
    int idx = 0;
    int top;
    for(int i = 1; i <= n; i++){
        top = -w;
        if(idx <= size) top = stations[idx];
        if(top >= i-w && top <= i+w){
            i = top+w;
            idx++;
        }
        else {
            i += w*2;
            answer++;
        }
    }
    

    return answer;
}