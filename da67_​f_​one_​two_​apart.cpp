#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m = 100000007;
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (3));
    if (n == 1) {
        cout << "3" << endl;
        return 0;
    }
    v[0][0] = 1;
    v[0][1] = 1;
    v[0][2] = 1;
    v[1][0] = 3;
    v[1][1] = 2;
    v[1][2] = 2;
    for (int i = 2; i < n; i++) {
        v[i][0] = v[i-1][0]%m + v[i-1][1]%m + v[i-1][2]%m; // เติม 0 ได้ทุกกรณี
        v[i][1] = (v[i][0] - (v[i-1][2] + v[i-2][2]) + m)%m; // ทั้งหมดที่เป็นไปได้ - (กรณีที่ก่อนหน้า 1,2 ตัวเป็น 2)
        v[i][2] = (v[i][0] - (v[i-1][1] + v[i-2][1]) + m)%m;
    }
    // // debug
    // for (auto &x : v) {
    //     for (auto & y:x) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    // //
    cout << (v[n-1][0]%m + v[n-1][1]%m + v[n-1][2]%m)%m;
}