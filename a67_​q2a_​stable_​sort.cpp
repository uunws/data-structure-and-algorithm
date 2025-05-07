#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> tmp = a;
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < m; i++) {
        vector<int> x(n+1);
        vector<int> tmp2(n+1);
        for (int j = 1; j <= n; j++) {
            cin >> x[j];
            tmp2[j] = a[x[j]];
        }
        bool issort = true;
        for (int j = 1; j <= n; j++) {
            if (tmp[j] != tmp2[j]) {
                issort = false;
                break;
            }
        }
        if (!issort) {
            cout << "0 0" << endl;
        } else {
            bool isstable = true;
            for (int j = 1; j < n; j++) {
                int x1 = j;
                int x2 = j+1;
                if (tmp2[x1] == tmp2[x2]) {
                    if (x[x1] > x[x2]) {
                        isstable = false;
                        break;
                    }
                }
            }
            if (isstable) {
                cout << "1 1" << endl;
            } else {
                cout << "1 0" << endl;
            }
        }
    }
}