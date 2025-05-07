#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(31, vector<int> (31));
    for (int i = 0; i <= 30; i++) {
        v[i][i] = 1;
        v[i][0] = 1;
    }
    for (int i = 1; i <= 30; i++) { // แต่ละแถว
        for (int j = 1; j <= i; j++) { // แต่ละตัวในแถว
            v[i][j] = v[i-1][j-1] + v[i-1][j];
        }
    }
    cout << v[n][k];
}