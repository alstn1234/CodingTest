#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = priorities.size();
    int value;
    int index = -1;
    while(true){
        value = priorities[++index];
        for(int i = 1 + index; i < priorities.size(); i++){
            if(value < priorities[i]){
                priorities.push_back(value);
                if(location == index)
                    location = priorities.size() - 1;
                break;
            }
        }
        if(index == location)
            return answer + location - priorities.size() + 1 ;
    }
}