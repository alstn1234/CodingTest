#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;

void dfs(vector<vector<string>> tickets, vector<string> visit, string world, int n){
    if(visit.size() == n){
        answer = answer.size() == 0 ? visit : answer < visit ? answer : visit;
        return;
    }
    
    for(auto& ticket : tickets){
        if(world == ticket[0]){
            ticket[0] = "";
            visit.emplace_back(ticket[1]);
            dfs(tickets, visit, ticket[1], n);
            visit.pop_back();
            ticket[0] = world;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    int n = tickets.size()+1;
    vector<string> visit;
    visit.emplace_back("ICN");
    dfs(tickets, visit, "ICN", n);
    return answer;
}