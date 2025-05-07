#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

// int get_sum(vector<int> &prefix, int l, int r) {
//     if (l != 0) return prefix[r] - prefix[l-1];
//     return prefix[r];
// }

int main() {
    int n;
    cin >> n;
    vector<int> prefix(n);
    map<int, int> m; // key : num value : prefixที่น้อยที่สุด
    int x;
    cin >> x;
    bool flag = true;
    if (x < 0) flag = false;
    prefix[0] = x;
    auto max_val = INT_MIN;
    int max_x = x;
    m[x] = 0;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        if (x < 0) flag = false;
        max_x = max(max_x, x);
        prefix[i] = prefix[i-1] + x;
        if (m.find(x) == m.end()) {
            m[x] = prefix[i-1];
        } else {
            m[x] = min(m[x], prefix[i-1]);
        }        
        max_val = max(max_val, prefix[i]-m[x]);   
    }
    // for (auto &p : m) {
    //     cout << p.first << "," << p.second << " ";
    // }
    // cout << endl;
    if (flag) {
        cout << max(max_x, max_val);
        return 0;
    }
    cout << max_val;

}