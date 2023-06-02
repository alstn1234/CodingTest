using namespace std;

int gcd_fun(int x, int y){
    int r;
    while(y != 0){
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}

long long solution(int w,int h) {
    long long answer = 1;
    if(w < h){
        int temp = h;
        h = w;
        w = temp;
    }
    int gcd = gcd_fun(w, h);
    return (long long)w*h - (long long)(w/gcd + h/gcd - 1)*gcd;
}