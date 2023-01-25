#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> num_1 = {1,2,3,4,5}; //5
    vector<int> num_2 = {2,1,2,3,2,4,2,5}; //8
    vector<int> num_3 = {3,3,1,1,2,2,4,4,5,5}; //10
    vector<int> correct(3);
    
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == num_1[i%5])
            correct[0]++;
        if(answers[i] == num_2[i%8])
            correct[1]++;
        if(answers[i] == num_3[i%10])
            correct[2]++;
    }
    int correct_max = max(correct[0], max(correct[1], correct[2]));
    for(int i = 0; i < correct.size(); i++)
        if(correct[i] == correct_max)
            answer.push_back(i+1);
    
    return answer;
}