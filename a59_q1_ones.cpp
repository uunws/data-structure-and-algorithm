#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int recur(vector<int> &q, int res) {
    if (res <= 6) {
        return res;
    }
    if (res <= 11) {
        return 2 + (11-res);
    }
    auto it = upper_bound(q.begin(), q.end(), res);
    auto m = (q[it - q.begin()-1])*(6);
    // cout << "res: " << res << ", m: " << m << ", it: " << *it << endl;
    if (res <= m) {
        it--;
        int t = res/(*it);
        int r = res%((*it)*t);
        // cout << "case1:" << r << endl; // debug
        // cout << "cnt1:" << t*(it - q.begin() + 1) << endl; // debug
        return t*(it - q.begin() + 1) + recur(q, r);
    } else {
        // cout << "case2:" << *it-res << endl; // debug
        // cout << *it << endl; // debug
        // cout << res << endl; // debug
        // cout << "cnt2:" << (it - q.begin() + 1) << endl; // debug
        return (it - q.begin() + 1) + recur(q, *it - res);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> q = {1,11,111,1111,11111,111111,1111111,11111111,111111111,1111111111};
    cout << recur(q, n);
}

