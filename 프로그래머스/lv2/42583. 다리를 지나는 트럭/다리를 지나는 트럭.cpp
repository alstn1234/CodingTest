#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    int pass_weight = 0;
    queue<pair<int, int>> que;
    que.emplace(truck_weights[0], answer);
    pass_weight += truck_weights[0];
    for(int i = 1; i < truck_weights.size(); i++){
        answer++;
        if(answer == que.front().second+bridge_length){
                pass_weight -= que.front().first;
                que.pop();
            }
        while(pass_weight+truck_weights[i] > weight){
                answer = que.front().second+bridge_length;
                pass_weight -= que.front().first;
                que.pop();
        }
        que.emplace(truck_weights[i], answer);
        pass_weight += truck_weights[i];
    }
    
    return bridge_length + que.back().second;
}