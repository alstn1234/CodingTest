#include <string>
#include <vector>

using namespace std;

vector<int> divisor(int a){
    vector<int> answer;
    for(int i = 2; i <= a; i++){
        while(a%i == 0){
            a /= i;
            answer.push_back(i);
        }
    }
    return answer;
}

int solution(int a, int b) {
    vector<int> aa = divisor(a);
    vector<int> bb = divisor(b);
    for(auto bbb : bb){
        bool k = false;
        for(int i = 0; i < aa.size(); i++){
            if(aa[i] == bbb){
                k=true;
                aa.erase(aa.begin()+i);
                break;
            }
        }
        if(!k && (bbb != 2 && bbb != 5))
            return 2;
    }
    return 1;
}