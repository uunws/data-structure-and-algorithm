#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<vector<int>> dist;
vector<vector<int>> w;

int main() {
    cin >> n >> m;
    dist.assign(n, vector<int> (n, 100000)); // ถ้าเป็น INT_MAX ค่าจะ overflow
    w.assign(n, vector<int> (n, 100000));
    for (int i = 0; i < m; i++) {
        int a,b,e;
        cin >> a >> b >> e;
        w[a][b] = e;
        w[b][a] = e;
    }
    // ชั้น0
    for (int i = 0; i < n; i++) { // ไล่ทุกคู่ปม
        for (int j = 0; j < n; j++) { 
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = w[i][j];
            }
        }
    }
    // for (auto & x : dist) {
    //     for (auto & y : x) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    // ชั้น 1->n
    for (int k = 0; k < n; k++) {
        // เริ่มไล่ k ตต 0 เพราะพอใส่เปน1แล้วกรณีที่มันผ่าน0ไม่ถูกคิด
        for (int i = 0; i < n; i++) { // ไล่ทุกคู่ปม    
            for (int j = 0; j < n; j++) {
                // if (i == 1 && j == 5) {
                //     cout << dist[i][j] << endl;
                //     cout << dist[i][k] << endl;
                //     cout << dist[k][j] << endl;
                // }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
        // cout << "-----" << k << "-----" << endl;
        // for (auto & x : dist) {
        //     for (auto & y : x) {
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }
    }
    int ans_max = 0;
    for (auto & x : dist) {
        for (auto & y : x) {
            // cout << y << " ";
            ans_max = max(ans_max, y);
        }
        // cout << endl;
    }
    cout << ans_max;
}