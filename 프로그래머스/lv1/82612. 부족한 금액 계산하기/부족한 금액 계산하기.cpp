using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    long long m = (long long)count*(count+1)/2*price;
    answer = m - money;
    if(answer < 0)
        return 0;
    return answer;
}