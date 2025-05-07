#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n,e,s;
vector<int> dist;
vector<vector<int>> G;

int main() {
    cin >> n >> e >> s;
    for (int i = 0; i < e; i++) {
        int a,b,w;
        cin >> a >> b >> w;
        G.push_back({a,b,w});
    }
    dist.assign(n, INT_MAX);
    dist[s] = 0;
    for (int i = 1; i <= n-1; i++) { // number of edges
        for (auto & subvec : G) {
            int a = subvec[0];
            int b = subvec[1];
            int w = subvec[2];
            if (dist[a] != INT_MAX && dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
            }
        }
    }
    for (auto & subvec : G) { // detect negative cycle
        int a = subvec[0];
        int b = subvec[1];
        int w = subvec[2];
        if (dist[a] != INT_MAX && dist[b] > dist[a] + w) { 
            // อย่าลืม check INT_MAX 
            // เพราะถ้า a เป็น INT_MAX dist[a] + w จะ overflow กลายเป็น ค่าติดลบ
            cout << "-1";
            return 0;
        }
    }
    for (auto & x : dist) {
        if (x == INT_MAX) {
            cout << "-1 "; 
        } else {
            cout << x << " ";
        }
    }
}