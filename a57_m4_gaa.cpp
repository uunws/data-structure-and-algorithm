#include <iostream>
using namespace std;

void recur(long long id, long long n, long long len) {
    long long prev_len = (len-3-id+1)/2;
    if (n > prev_len && n <= prev_len + id + 3) {
        long long res = n - prev_len;
        if (res == 1) {
            cout << "g";
        } else {
            cout << "a";
        }
    } else if (n <= prev_len) {
        recur(id-1, n, prev_len);
    } else {
        recur(id-1, n-(prev_len + id + 3), prev_len);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n;
    cin >> n;
    if (n <= 3) {
        if (n == 1) cout << "g";  return 0;
        if (n == 2) cout << "a";  return 0;
        if (n == 3) cout << "a";  return 0;
    }
    // vector<long long> prefix(50000);
    // prefix[0] = 3;
    long long cnt = 1;
    long long len = 3;
    while (len < n) {
        len = len*2 + cnt + 3;
        cnt++;
    }
    // find which part is n in
    // cnt-1 is the index where ครอบคลุม n
    long long id = cnt-1;
    recur(id, n, len);
}