#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < k; i++) {
        int p, w;
        cin >> p >> w;
        int cnt = p-1;
        int res = 0;
        while (res < w) {
            res += d[cnt] - m;
            cnt++;
        }
        cout << cnt << "\n";
    }
}