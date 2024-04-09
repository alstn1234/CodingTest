#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int answer = 0;
    int arr1Size = arr1.size();
    int arr2Size = arr2.size();
    
    if(arr1Size != arr2Size)
        answer = arr1Size > arr2Size ? 1 : -1;
    else{
        int arr1Sum = accumulate(arr1.begin(), arr1.end(), 0);
        int arr2Sum = accumulate(arr2.begin(), arr2.end(), 0);
        answer = arr1Sum == arr2Sum ? 0 : arr1Sum > arr2Sum ? 1 : -1;
    }
            
    
    return answer;
}