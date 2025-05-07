#include <iostream>
#include <vector>
using namespace std;

bool perm_and_checksum(vector<long long> &v, int n, int len, vector<bool> &used, vector<long long> &sol, long long x) {
    if (len == 3) {
        long long sum = sol[0] + sol[1] + sol[2];
        // cout << sol[0] << " " << sol[1] << " " << sol[2] << endl; // debug
        // if (sum == x) cout << "correct: " << sol[0] << " " << sol[1] << " " << sol[2] << endl; // debug
        return sum == x;
    }
    if (len < 3) {
        for (int i = 0; i < n; i++) {
            if (used[i] == false) {
                used[i] = true;
                sol[len] = v[i];
                bool res = perm_and_checksum(v, n, len+1, used, sol, x);
                used[i] = false;
                if (res) return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> v;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        v.push_back(x);
    }
    vector<int> ans(m);
    vector<bool> used(n, false);
    vector<long long> sol(3, 0);
    for (int i = 0; i < m; i++) {
        long long x;
        cin >> x;
        // cout << "----" << x << "----" << endl; // debug
        if (perm_and_checksum(v, n, 0, used, sol, x)) {
            // ans[i] = 1;
            cout << "YES" << endl;
        } else {
            // ans[i] = 0;
            cout << "NO" << endl;
        }
    }
    // for (auto & i : ans) {
    //     if (i == 1) cout << "YES" << endl;
    //     if (i == 0) cout << "NO" << endl;
    // }
    return 0;
}