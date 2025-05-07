#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        int idx = 0;
        int cnt = 0;
        while (true) {
            if (A[idx] > k) {
                cnt++;
            }
            if (A[idx] == k) break;
            idx++;
        }
        cout << cnt << endl;
    }
}