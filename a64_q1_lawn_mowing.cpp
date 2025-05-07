#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> prefix(n);
    int x;
    cin >> x;
    prefix[0] = x + k;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        prefix[i] = prefix[i-1] + x + k;
    }
    // for (auto &x : prefix) {
    //     cout << x << " ";
    // }
    // cout << endl;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        auto it = upper_bound(prefix.begin()+a, prefix.end(), (a != 0)? (b+prefix[a-1]) : b);
        // if (it == prefix.end()) cout << "0"; return 0;
        // cout << *it << endl;
        // cout << prefix[a-1] << endl;
        if (it == prefix.begin()) {
            cout << 0 << endl;
        } else {
            it--;
            cout << *it - prefix[a-1] - (it - prefix.begin() - a +1)*k << endl;;
        }
    }
}