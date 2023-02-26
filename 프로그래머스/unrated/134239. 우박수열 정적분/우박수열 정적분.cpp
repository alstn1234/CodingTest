#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double> v;
    while(k != 1){
        int b_k = k;
        double area = 0.0;
        if(k%2 == 0){
            k /= 2;
            area += k + (double)(b_k-k)/2;
        }
        else{
            k = k*3+1;
            area += b_k + (double)(k-b_k)/2;
        }
        v.push_back(area);
    }
    for(auto range : ranges){
        int n = range[1]+v.size()-1;
        if(n+1 < range[0]){
            answer.push_back(-1);
            continue;
        }
        double sum = 0.0;
        for(int i = range[0]; i <= n; i++){
            sum += v[i];
        }
        answer.push_back(sum);
    }
    
    return answer;
}