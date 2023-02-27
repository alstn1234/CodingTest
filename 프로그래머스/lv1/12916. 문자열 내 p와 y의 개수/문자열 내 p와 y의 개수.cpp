#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p = 0, y = 0;
    for(const char c : s){
        if(c == 'y' || c == 'Y')
            y++;
        if(c =='p' || c == 'P')
            p++;
    }

    return y==p;
}