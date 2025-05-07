#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        int min = 0;
        int max = v.size() - 1; // อย่าลืม -1 ออก
        if (x < v[0]) {
            cout << "-1" << endl;
        } else {
            while (min < max) {
                int mid = (min+max)/2;
                // cout << "debug" << v[mid] << endl;
                if (v[mid] < x) min = mid + 1;
                if (v[mid] >= x) max = mid;
            }
            if (v[max] > x) max--;
            // check if next to max to the right is max
            while (v[max + 1] == v[max]) {
                max++;
            }
            cout << max << endl;
            // if (max == 258019) {
            //     cout << n-1 << endl;
            // } else {
            //     cout << max << endl;
            // }
        }
    }
}