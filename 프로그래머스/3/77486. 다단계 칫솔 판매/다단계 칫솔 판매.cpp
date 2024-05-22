#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, int> money;
    map<string, string> parentMap;
    
    for(int i = 0; i < enroll.size(); i++)
        parentMap[enroll[i]] = referral[i];
    
    for(int i = 0; i < seller.size(); i++){
        money[seller[i]] += amount[i]*90;
        int price = amount[i]*10;
        string parent = parentMap[seller[i]];
        while(parent != "-" && price != 0){
            money[parent] += price;
            price /= 10;
            money[parent] -= price;
            parent = parentMap[parent];
            
        }
    }
    
    for(auto e : enroll){
        answer.push_back(money[e]);   
    }
    
    return answer;
}