#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> cp_plays;

bool cmp(pair<string, int> i, pair<string, int> j){
    return i.second > j.second;
}

bool cmp2(int i, int j){
    return cp_plays[i] > cp_plays[j];
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    cp_plays = plays;
    map<string, int> m;
    
    for(int i = 0; i < genres.size(); i++){
        m[genres[i]] += plays[i];
    }
    
    vector<pair<string, int>> music(m.begin(), m.end());
    sort(music.begin(), music.end(), cmp);
    
    for(auto genre : music){
        vector<int> v;
        for(int i = 0; i < genres.size(); i++){
            if(genre.first == genres[i]){
                v.push_back(i);
            }
        }
        sort(v.begin(), v.end(), cmp2);
        int k = v.size() == 1 ? 1 : 2;
        answer.insert(answer.end(), v.begin(), v.begin()+k);
    }
    return answer;
}