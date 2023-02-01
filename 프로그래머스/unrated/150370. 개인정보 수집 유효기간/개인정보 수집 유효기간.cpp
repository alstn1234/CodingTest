#include <string>
#include <vector>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int now_year = stoi(today.substr(0, 4));
    int now_month = stoi(today.substr(5, 2));
    int now_day = stoi(today.substr(8, 2));
    int i = 0;
    for(string pri : privacies){
        for(string term : terms){
            if(pri[11] != term[0])
                continue;
            int year = stoi(pri.substr(0, 4));
            int month = stoi(pri.substr(5, 2)) + stoi(term.substr(2));
            int day = stoi(pri.substr(8, 2)) - 1;
            while(month > 12){
                month -= 12;
                year += 1;
            }
            if(day == 0){
                day = 28;
                month -= 1;
            }
            if(now_year < year)
                break;
            if(now_year == year && now_month < month)
                break;
            if(now_year == year && now_month == month && now_day <= day)
                break;
            answer.push_back(i+1);
            break;
        }
        i++;
    }
    return answer;
}