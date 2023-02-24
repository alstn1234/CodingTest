#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int i = 0, j = people.size()-1;
    sort(people.rbegin(), people.rend());
    
    while(i <= j){
        answer++;
        if(i == j)
            i++;
        else if(people[i]+people[j] <= limit){
            i++; j--;
        }
        else
            i++;    
    }
    return answer;
}