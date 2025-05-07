#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].second++;
    }
    sort(v.begin(), v.end());
    auto x = v[0].first;
    auto y = v[0].second;
    for (int i = 1; i < n; i++) {
        auto curr_x = v[i].first;
        auto curr_y = v[i].second;
        if (curr_x <= y) {
            y = max(y, curr_y);
        } else {
            cout << x << " " << y-1 << " ";
            x = curr_x;
            y = curr_y;
        }
    }
    cout << x << " " << y-1 << " ";
}