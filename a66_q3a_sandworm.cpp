#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int r,c,k;
int N[800][800];
int S[800][800];
vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1};
map<int, int> sz;

// 0-based
// region : 0 ที่อยู่ติดกัน

void fill (int i, int j, int x, int d[800][800]) {
    if (i < 0 || j < 0 || i >= r || j >= c) return; // if out-of-bound -> pass
    if (d[i][j] != 0) return; // if visited -> pass
    d[i][j] = x; // mark the cell with region id
    sz[x]++; // increase size of region id
    for (int m = 0; m < 4; m++) {
        fill(i + dx[m], j + dy[m], x, d);
    }
}

int main() {
    cin >> r >> c >> k;
    // N.assign(r+1, vector<int> (c+1, 0));
    // S.assign(r+1, vector<int> (c+1, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> N[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> S[i][j];
        }
    }
    int ptr = 2; // start at 2 so that it wont affect 0,1
    fill(0,0,ptr++,N); // start at (0,0) ptr++ so that next ptr be unique id
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (S[i][j] == 0) {
                fill(i, j, ptr++, S); // fill south seperate from north
            }
        }
    }
    int ans = sz[2]; // start with region 2 (in N)
    while (k--) {
        int i,j;
        cin >> i >> j;
        i--; j--;
        if (N[i][j] != 2) continue; // N ต้องเปน2เท่านั้น เพราะเริ่มเดินจาก (0,0) เลยอยู่ได้แค่ region นี้เท่านั้น
        ans = max(ans, sz[2] + sz[S[i][j]]); // เลือกว่าจะไปเดินอีกซีกโลก หรือ อยู่ซีกโลกเดิม
        // เราเดินยังไงก้ได้ในซีกโลกเหนือ เพราะค่าที่มากที่สุดก้คือ เดินจนตัวสุดท้ายต้องไปซีกโลกใต้
        // ซีกโลกใต้ ก้บวกขนาดของregionที่coordinateนั้นอยู่
    }
    cout << ans;
}