#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    if(A == B)
        return 0;
    for(int i = 0; i < B.length(); i++){
        B += B[0];
        B = B.substr(1);
        if(A == B)
            return i + 1;
    }
    return -1;
}