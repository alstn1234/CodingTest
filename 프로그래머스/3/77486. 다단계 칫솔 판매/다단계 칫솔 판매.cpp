#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, int> defaultMoney;
    map<string, int> addMoney;
    map<string, string> parentMap;
    for(int i = 0; i < enroll.size(); i++)
        parentMap[enroll[i]] = referral[i];
    
    for(int i = 0; i < seller.size(); i++){
        defaultMoney[seller[i]] += amount[i]*90;
        
        string parent = parentMap[seller[i]];
        int price = amount[i]*10;
        while(parent != "-" && price != 0){
            addMoney[parent] += price;
            price /= 10;
            defaultMoney[parent] -= price;
            parent = parentMap[parent];
            
        }
    }
    
    for(auto e : enroll){
        answer.push_back(defaultMoney[e] + addMoney[e]);
    }
    
    return answer;
}