#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> m;
    for(int i = 0; i < players.size(); i++)
        m[players[i]] = i;
    
    for(auto call : callings){
        int n = m[call];
        string temp;
        m[players[n]] = n-1;
        m[players[n-1]] = n;
        temp = players[n];
        players[n] = players[n-1];
        players[n-1] = temp;
    }
    
    return players;
}