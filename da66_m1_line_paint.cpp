#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].second++;
    }
    sort(v.begin(), v.end());
    int x = v[0].first;
    int y = v[0].second;
    for (int i = 1; i < n; i++) {
        int curr_x = v[i].first;
        int curr_y = v[i].second;
        if (curr_x <= y) {
            y = max(y, curr_y);
        } else {
            cout << x << " " << y - 1 << " ";
            x = curr_x;
            y = curr_y;
            
        }
    }
    cout << x << " " << y - 1;
}