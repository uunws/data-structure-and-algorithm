#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxkadane(vector<int> &v, int n, bool flag) {
    int maxEnding = -1000000000;
    int res = -100000000;
    int a = (flag)? 0 : 1;
    for (int i = a; i < n; i++) {
        if (flag) {
            if (i%2==0) { // เริ่มต้นได้แค่ที่คู่ 
                maxEnding = max(maxEnding + v[i], v[i]);
            } else {
                maxEnding = maxEnding + v[i]; // เริ่มไม่ได้
            }
        } else { // vector ที่ กลับเครื่องหมาย
            if (i%2!=0) { // เริ่มต้นได้แค่ที่คี่
                maxEnding = max(maxEnding + v[i], v[i]);
            } else {
                maxEnding = maxEnding + v[i]; // เริ่มไม่ได้
            }
        } 
        // maxEnding = max(maxEnding + v[i], v[i]);
        res = max(res, maxEnding);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        int x;
        cin >> x;
        cout << x;
        return 0;
    }
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i%2==0) {
            v1[i] = x;
            v2[i] = -x;
        } else {
            v1[i] = -x;
            v2[i] = x;
        }
    }
    int ans = max(maxkadane(v1, n, true), maxkadane(v2,n, false));
    cout << ans;
}