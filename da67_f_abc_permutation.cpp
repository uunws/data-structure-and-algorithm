#include <iostream>
#include <vector>
#include <set>
using namespace std;
void perm_kn(string s, int i, int j, int k, set<string> &ans, int max_len) {
    if (s.size() < max_len) {
        if (i > 0) {
            perm_kn(s + "A", i - 1, j, k, ans, max_len);
        }
        if (j > 0) {
            perm_kn(s + "B", i, j - 1, k, ans, max_len);
        }
        if (k > 0) {
            perm_kn(s + "C", i, j, k - 1, ans, max_len);
        }
    } else {
        ans.insert(s);
    }
}
int main() {
    int N, i, j, k;
    cin >> N >> i >> j >> k;
    set<string> ans;
    perm_kn("", i, j, k, ans, N);
    cout << ans.size() << endl;
    for (auto & x : ans) {
        cout << x << endl;
    }
}