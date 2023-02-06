#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int answer = 0;
map<int, bool> m;

bool is_prime(int num){
    if(num == 2)
        return true;
    if(num <= 1)
        return false;
    for(int i = 2; i < num-1; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

void dfs(string numbers, string num, int size){
    cout << num << " " << is_prime(stoi(num)) << endl;
    if(is_prime(stoi(num)) && !m[stoi(num)]){
        answer++;
        m[stoi(num)] = true;
    }
    if(num.length() == size)
        return;
    for(int i = 0; i < numbers.length(); i++){
        string num2 = num + numbers[i];
        string numbers2 = numbers;
        numbers2.erase(numbers2.begin()+i);
        dfs(numbers2, num2, size);
    }
    
}

int solution(string numbers) {
    for(int i = 0; i < numbers.length(); i++){
        string num = numbers.substr(i, 1);
        string numbers2 = numbers;
        numbers2.erase(numbers2.begin()+i);
        dfs(numbers2, num, numbers.length());
        
    }
    return answer;
}