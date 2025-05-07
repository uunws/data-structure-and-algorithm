#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // vector<int> table(n);
    // table[0] = v[0];
    // table[1] = v[0] + v[1];
    // table[2] = max(v[0]+v[1]+v[2], v[0]+v[2]);
    int prev1 = v[0];
    int prev2 = v[0] + v[1];
    int prev3 = max(v[0]+v[1]+v[2], v[0]+v[2]);
    int res = prev3;
    for (int i = 3; i < n; i++) {
        // table[i] = max({table[i-1], table[i-2], table[i-3]}) + v[i];
        res = max({prev1, prev2, prev3}) + v[i];
        prev1 = prev2;
        prev2 = prev3;
        prev3 = res;    
    }
    // cout << table[n];
    cout << res;
}