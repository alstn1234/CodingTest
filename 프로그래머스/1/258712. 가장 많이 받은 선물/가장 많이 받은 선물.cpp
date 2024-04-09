#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, map<string, int>> giftData;
    map<string, int> giftExp;
    map<string, int> receiveGift;
    
    for(auto& gift : gifts){
        string bring, receive;
        stringstream ss(gift);
        ss >> bring; ss >> receive;
        giftData[bring][receive]++;
        giftExp[bring]++;
        giftExp[receive]--;
    }
    
    for(int i = 0; i < friends.size(); i++){
        for(int j = i+1; j < friends.size(); j++){
            string f1 = friends[i], f2 = friends[j];
            if(giftData[f1][f2] == giftData[f2][f1]){
                if(giftExp[f1] > giftExp[f2]) receiveGift[f1]++;
                else if(giftExp[f1] < giftExp[f2]) receiveGift[f2]++;
            }
            else{
                if(giftData[f1][f2] > giftData[f2][f1]) receiveGift[f1]++;
                else if(giftData[f1][f2] < giftData[f2][f1]) receiveGift[f2]++;
            }
        }
    }
    
    for(auto itr = receiveGift.begin(); itr != receiveGift.end(); itr++){
        answer = max(answer, itr->second);
    }
    return answer;
}