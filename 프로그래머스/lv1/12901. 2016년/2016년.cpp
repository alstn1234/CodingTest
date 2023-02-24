#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int n = 0;
    vector<int> month = {
      31,29,31,30,31,30,31,31,30,31,30,31  
    };
    vector<string> date = {
        "FRI","SAT","SUN","MON","TUE","WED","THU"
    };
    for(int i = 0; i <= a-2; i++){
        n += month[i];
    }
    n += b-1;
    
    return date[n%7];
}