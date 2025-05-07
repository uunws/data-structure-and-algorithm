#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n,m,k;
int v;
vector<int> dist;
vector<vector<int>> G;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // ไม่ต้องทำทุกค่าstart ทีละครั้ง
    // ให้ assign ค่าที่เปนจุดstartได้ว่า0ไปเลย 
    // หมายความว่ามี0เส้นเชื่อมก็อยู่จุดนั้นอยู่แล้ว ก็คืออยู่ตรงนั้นตตเริ่มเลย
    // คำตอบที่ได้จะเปนshortest pathที่เริ่มต้นจากstartที่ให้shortest path
    cin >> n >> m >> k;
    cin >> v;
    dist.assign(n, INT_MAX); // can start at all member in start
    for (int i = 0; i < k ;i++) {
        int x;
        cin >> x;
        dist[x] = 0; // 0 mean can start, INT_MAX mean cannot start here
    }
    G.assign(m, vector<int> (3));
    for (int i = 0; i < m; i++) {
        int a,b,w;
        cin >> a >> b >> w;
        G[i] = {a,b,w};
    }
    for (int i = 0; i < n; i++) {
        for (auto & subvec : G) {
            int a = subvec[0];
            int b = subvec[1];
            int w = subvec[2];
            if (dist[a] != INT_MAX && dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
            }
        } 
    }
    cout << dist[v];
}