#include <iostream>

using namespace std;

int mod(int x, int n, int k) {
    if (n == 1) {
        return x % k;
    }
    if (n % 2 == 0) {
        int tmp = mod(x, n/2, k);
        return (tmp*tmp) % k;
    } else {
        int tmp = mod(x, n/2, k);
        tmp = (tmp*tmp)%k;
        return (tmp * (x % k)) % k;
    }
}

int main() {
    int x, n, k;
    cin >> x >> n >> k;
    cout << mod(x, n, k);
}