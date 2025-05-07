#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    vector<int> prefix(n);
    prefix[0] = v[0].second;
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + v[i].second;
    }
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        auto it = lower_bound(prefix.begin(), prefix.end(), x);
        cout << v[it - prefix.begin()].first << endl;
    }
}
