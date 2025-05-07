#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// ใช้ floyd-warshall algorithm ในการตรวจหา negative cycle
// เปลี่ยนจากการคูณกัน เปนการบวกกันของ log
// log(A*B*C) = log(A) + log(B) + log(C) > 0 (A*B*C > 1)
// log(A) = -log(A) ใช้เปน -log แทน และใช้การตรวจหา negative cycle แทน
// เพราะถ้ามี negative cycle -> ทำกำไรได้เรื่อยๆ

int main() {
    int k;
    cin >> k;
    for (int r = 0; r < k; r++) {
        int n;
        cin >> n;
        vector<vector<double>> arr(n, vector<double> (n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double x;
                cin >> x;
                arr[i][j] = -log2(x);
            }
        }
        for (int p = 0; p < n; p++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    arr[i][j] = min(arr[i][j], arr[i][p] + arr[p][j]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (arr[i][i] < 0.0) {
                cout << "YES" << endl;
                break;
            } else {
                cout << "NO" << endl;
                break;
            }
        }
    }
}