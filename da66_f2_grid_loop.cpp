#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n,m;
vector<pair<int, int>> d1 = {{0,-1},{-1,0},{-1,0},{0,1},{1,0},{0,-1}};
vector<pair<int, int>> d2 = {{0,1},{1,0},{0,1},{1,0},{0,-1},{-1,0}};
map<pair<int, int>, int> node; // contain ptr(unique id)
map<int, vector<int>> edge; // store graph
bool visited[1000000];

int ans = 0; // max path
int cnt = 0; // num of loop

bool dfs(int a, int parent, int len) {
    if (visited[a]) { // found cycle
        ans = max(ans, len);
        cnt++;
        return true;
    }
    visited[a] = 1;
    for (auto & b : edge[a]) {
        if (b != parent) {
            if (dfs(b,a,len+1)) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // cin >> n >> m;
    scanf("%d", "%d", &n, &m);
    int ptr = 1;
    // expand size of grid (inputที่ตนเลขคี่ ค่าu,vจะอยู่ตนเลขคู่)
    // แก้ปัญหาเส้นติดกันและทับกัน 
    for (int i = 1; i <= 2 * n; i+=2) {
        for (int j = 1; j <= 2 * m; j+=2) {
            int x;
            // cin >> x;
            scanf("%d", x);
            pair<int, int> u = {i + d1[x-1].first, j + d1[x-1].second};
            pair<int, int> v = {i + d2[x-1].first, j + d2[x-1].second};
            if (!node[u]) { // there is no node u in map
                node[u] = ptr++;
            }
            if (!node[v]) {
                node[v] = ptr++;
            }
            edge[node[u]].push_back(node[v]);
            edge[node[v]].push_back(node[u]);
        }
    }
    for (int i = 1; i <= node.size(); i++) { // node is map
        if (visited[i] == 0) {
            dfs(i, -1, 0);
        }
    }
    // cout << cnt << " " << ans;
    printf("%d %d", cnt, ans);
}