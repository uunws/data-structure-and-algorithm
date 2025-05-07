#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A(r,c+1) B(r+1,c) C(r-1,c)
void path(int x, int y, string op, vector<vector<int>> &check ,vector<string> &ans, int r, int c) {
    if (x == r-1 && y == c-1) { // 0 base
        // ans.push_back(op);
        cout << op << endl;
        return;
    }
    // for op A
    check[x][y] = 2;
    if (y + 1 < c && check[x][y+1] == 0) {
        path(x, y+1, op+"A", check, ans, r, c);
    }
    // for op b
    if (x + 1 < r && check[x+1][y] == 0) {
        path(x+1, y, op+"B", check, ans, r, c);
    }
    // for op c
    if (x - 1 >= 0 && check[x-1][y] == 0) {
        path(x-1, y, op+"C", check, ans, r, c);
    }
    check[x][y] = 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int r, c;
    cin >> r >> c;
    vector<vector<int>> check(r,vector<int>(c, 0)); // เก็บช่องห้ามเข้า, ผ่านไปแล้ว
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            int x;
            cin >> x; // 0: ปกติ, 1:ห้ามเข้า
            if (x == 1) {
                check[i][j] = 1; // ห้ามเข้า = 1, ไปแล้ว = 2
            } 
        }
    }
    vector<string> ans;
    path(0, 0, "", check, ans, r, c); // 0 base
    // for (auto &x : ans) {
    //     cout << x << endl;
    // }
    cout << "DONE";
}
