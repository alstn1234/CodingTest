#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(string s1, string s2){
    string head1 = "", head2 = "";
    int num1, num2;
    int i = 0;
    
    while(i < s1.length() && (s1[i] < '0' || s1[i] > '9')){
        head1 += tolower(s1[i++]);
    }
    string n = "";
    while(i < s1.length() && s1[i] >= '0' && s1[i] <= '9'){
        n += s1[i++];
    }
    num1 = stoi(n);
    
    i = 0; n = "";
    while(i < s2.length() && (s2[i] < '0' || s2[i] > '9')){
        head2 += tolower(s2[i++]);
    }
    while(i < s2.length() && s2[i] >= '0' && s2[i] <= '9'){
        n += s2[i++];
    }
    num2 = stoi(n);
    
    if(head1 > head2)
        return false;
    else if(head1 < head2)
        return true;
    if(num1 < num2)
        return true;
    return false;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), cmp);
    return files;
}