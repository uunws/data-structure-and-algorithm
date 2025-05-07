#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    vector<vector<int>> v(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                v[i][j] = 0;
            } else {
                v[i][j] = max(0, A[i]*A[j]);
            }
        }
    }
    // sum all diagonal and find max
    int max1 = 0;
    for (int j = 0; j < n; j++) {
        // j = 0 -> p 1 ตัว
        // j = 1 -> p 2 ตัว
        // j = n-1 -> p n ตัว
        int x = 0;
        int y = j;
        int sum1 = 0;
        for (int p = 0; p <= j && x+p < n && y-p >= 0; p++) {
            sum1 += v[x+p][y-p];
        }
        max1 = max(max1, sum1);
    }
    int max2 = 0;
    for (int i = 0; i < n; i++) {
        int x = i;
        int y = 0;
        int sum2 = 0;
        for (int p = 0; p <= i && x+p < n && y-p >= 0; p++) {
            sum2 += v[x+p][y-p];
        }
        max2 = max(max2, sum2);
    }
    int max_sum = max(max1, max2);
    // // debug
    // for (auto &x : v) {
    //     for (auto &y : x) {
    //         cout << y << " "; 
    //     }
    //     cout << endl;
    // }
    // //
    cout << max_sum;
}