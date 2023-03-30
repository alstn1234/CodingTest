#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    if(sticker.size() == 1)
        return sticker.back();
    vector<int> dp1(sticker.begin(), sticker.end()-1);
    vector<int> dp2(sticker.begin()+1, sticker.end());
    
    dp1[1] = max(dp1[0], dp1[1]);
    dp2[1] = max(dp2[0], dp2[1]);
    
    for(int i = 2; i < dp1.size(); i++)
        dp1[i] = max(dp1[i]+dp1[i-2], dp1[i-1]);
    
    for(int i = 2; i < dp2.size(); i++)
        dp2[i] = max(dp2[i]+dp2[i-2], dp2[i-1]);

    return max(dp1.back(), dp2.back());
}