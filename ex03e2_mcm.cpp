#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 0; i <= n; i++) { // n+1
        cin >> v[i];
    }
    vector<vector<int>> b(n, vector<int>(n, 0)); // 0-base
    for (int len = 1; len < n; len++) { // ค.ยาวของเส้นทแยงมุม = n - len
        for (int i = 0; i < n-len; i++) { // 0-base (row)
            if (len == 1) {
                b[i][i+1] = v[i]*v[i+1]*v[i+2];
            } else {
                int j = i + len;
                b[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    int op = b[i][k] + b[k+1][j] + v[i]*v[k+1]*v[j+1];
                    // cout << "---debug---" << endl;
                    // cout << "j: " << j << endl; // debug
                    // cout << b[i][k] << " " << b[k+1][j] << " " << v[i]*v[k+1]*v[j+1] << endl; // debug
                    // cout << op << endl; // debug
                    b[i][j] = min(b[i][j], op); // not debug
                    // cout << b[i][j] << endl; // debug
                    // cout << "---debug---" << endl;
                }
            }
        }
    }
    // // debug
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << b[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // //
    cout << b[0][n-1];
}