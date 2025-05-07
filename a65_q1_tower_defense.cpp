#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<int> p;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        p.push_back(x);
    }
    vector<int> h;
    for (int i = 0; i < m; i++) {
        int y;
        cin >> y;
        h.push_back(y);
    }
    vector<int> t;
    for (int i = 0; i < k; i++) {
        int z;
        cin >> z;
        t.push_back(z);
    }
    for (auto & x : t) { // ตน.ของป้อมแต่ละป้อม
        // cout << "x = " << x << endl;
        int shoot_left = max(0,x - w);
        int shoot_right = min(n,x + w);
        // cout << shoot_left << "||" << shoot_right << endl;
        // cout << "-------" << endl;
        for (int i = 0; i < m; i++) {
            if (p[i] >= shoot_left && p[i] <= shoot_right) {
                h[i] = max(0, h[i]-1);
                break;
                // cout << "debug" << h[i];
            }
        }
    }
    int sum = 0;
    for (auto & x : h) {
        sum += x;
    }
    cout << sum;
}