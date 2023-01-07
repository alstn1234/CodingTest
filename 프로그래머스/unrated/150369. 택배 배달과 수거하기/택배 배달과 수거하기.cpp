#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int del_index = n-1;
    int pick_index = n-1;
    int value;
    int cap2; 
    
    while(deliveries[del_index]==0){
        if(del_index == 0){
            del_index--;
            break;
        }
            del_index--;
    }
    
    while(pickups[pick_index]==0){
        if(pick_index == 0){
            pick_index--;
            break;
        }
            pick_index--;
    }
    
    while(del_index != -1 || pick_index != -1){
        value = (del_index >= pick_index) ? 2*(del_index+1) : 2*(pick_index+1);
        answer += value;
        
        cap2 = cap;
        while(cap2 != 0 && del_index >= 0){
            if(deliveries[del_index] >= cap2){
                deliveries[del_index] -= cap2;
                cap2 = 0;
            }else{
                cap2 -= deliveries[del_index];
                deliveries[del_index] = 0;
            }
            
            while(deliveries[del_index]==0){
                if(del_index == 0){
                    del_index--;
                    break;
                }
                del_index--;
            }
        }
            
            
        cap2 = cap;
        while(cap2 != 0 && pick_index >= 0){
            if(pickups[pick_index] >= cap2){
                pickups[pick_index] -= cap2;
                cap2 = 0;
            }else{
                cap2 -= pickups[pick_index];
                pickups[pick_index] = 0;
            }
            while(pickups[pick_index]==0){
                if(pick_index == 0){
                    pick_index--;
                    break;
                }
                pick_index--;
            }
        }
            
    }
    
    return answer;
}