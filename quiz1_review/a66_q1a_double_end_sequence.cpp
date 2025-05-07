#include <iostream>
#include <map>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> prefix(n);
    bool flag1 = false;
    // bool flag2 = false;
    int x;
    cin >> x;
    if (x > 0) flag1 = true;
    // if (x < 0) flag2 = true;
    prefix[0] = x;
    map<int, int> min_pre;
    min_pre[x] = 0;
    int max_out = INT_MIN;
    int max_x = x; // for case all negative (flag1)
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        max_x = max(max_x, x);
        if (x > 0) flag1 = true;
        // if (x < 0) flag2 = true; 
        prefix[i] = prefix[i-1] + x;
        auto it = min_pre.find(x);
        if (it == min_pre.end()) { // ยังไม่มี ใส่เข้่าไปก่อน
            min_pre[x] = prefix[i-1]; // i-1 เพราะ ผลรวมรวมตัวซ้ำทั้งสองฝั่งด้วย
        } else {
            min_pre[x] = min(min_pre[x], prefix[i-1]);
        }
        max_out = max(max_out, prefix[i]-min_pre[x]);
    }
    if (!flag1) { // if it all negative, cout the max value
        cout << max_x << endl;
        return 0;
    }
    // if (!flag2) {
    //     cout << max_x << endl;
    //     return 0;
    // }
    cout << max_out;

}