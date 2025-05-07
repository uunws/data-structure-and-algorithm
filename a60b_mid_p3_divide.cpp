#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m = 1997;
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << "1" << endl;
        return 0;
    }
    // Stirling numbers of the second kind
    // (n, k) = k*(n-1, k) + (n-1, k-1)
    vector<vector<int>> arr(n, vector<int> (n, 0)); // row = n, col = k
    for (int i = 0; i < n; i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;
    }
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < i+1; j++) {
            arr[i][j] = (((j+1)%m)*arr[i-1][j]%m)%m + arr[i-1][j-1]%m;
        }
    }
    cout << arr[n-1][k-1]%m;
}