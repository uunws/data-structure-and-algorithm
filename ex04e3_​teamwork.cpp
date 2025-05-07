#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> t(m);
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    vector<double> res(n);
    double ans = 0;
    for (int i = 0; i < n; i++) {
        res[i] = t[i];
        ans += t[i];
    }
    for (int i = n; i < m; i++) {
        int mod = i % n;
        res[mod] += t[i];
        ans += res[mod];
    }
    double avg = ans/m;
    cout << fixed << setprecision(3) << avg;
}