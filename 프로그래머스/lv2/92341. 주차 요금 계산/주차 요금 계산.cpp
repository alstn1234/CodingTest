#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> m;
    map<string, int> price;
    
    for(string record : records){
        string car_number = record.substr(6, 4);
        int time = stoi(record.substr(0, 2))*60 + stoi(record.substr(3, 2));
        if(record[12] == 'N'){
            m[car_number] = time;
        }
        else{
            time -= m[car_number];
            m.erase(car_number);
            price[car_number] += time;
        }
    }
    
    for(auto it = m.begin(); it != m.end(); it++){
        int time = 24*60-1;
        time -= it->second;
        price[it->first] += time;
    }
    
    for(auto it = price.begin(); it != price.end(); it++){
        int time = it->second;
        if(time <= fees[0]){
            answer.push_back(fees[1]);
            continue;
        }
        int unit_time = time-fees[0];
        int money = fees[1] + unit_time/fees[2]*fees[3];
        if(unit_time%fees[2] != 0)
            money += fees[3];
        answer.push_back(money);
    }
    return answer;
}