#include <iostream>

using namespace std;

void gaa(int len, int cnt, int n) {
    long long prev = (len - (1 + cnt + 2))/2;
    if (n > prev && n <= prev + id + 1 + 2) {
        long long res = n - prev;
        if (res == 1) cout << "g"; else cout << "a";
    } else if ()
}

int main() {
    int n;
    cin >> n;
    int num = 3;
    int cnt = 1;
    int curr_num;
    while(num < n) {
        curr_num = num;
        num = 2*num + cnt + 3;
        cnt++;
    }
    gaa(1, num, cnt-1, n);
}