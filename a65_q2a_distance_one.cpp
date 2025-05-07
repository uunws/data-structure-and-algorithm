#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int mod = 100000007;
    int n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    v[1] = 2; // 0, 1 
    for (int i = 2; i <= k; i++) {
        v[i] = i%mod + 1;
    }
    for (int i = k+1; i <= n; i++) {
        v[i] = v[i-1]%mod + v[i-k]%mod;
    }
    cout << v[n]%mod;
}