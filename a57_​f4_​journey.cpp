#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

int n;

vector<vector<int>> g;
vector<int> pf;

int ALL_VISITED;

vector<vector<int>> dp;

int dfs(int node, int mask) {
    if (mask == ALL_VISITED) {
        if (node == n-1) return 0;
        else return -10000000; // mean this path is invalid (not end with last node)
        // use very min value (every score is greater than this value) 
        // so this path wont get to dicided that it is a valid answer
        // at ans = max(ans, new_ans) this wont select -1000000, because we ensure that every score is more than this number
    }
    if (dp[mask][node] != -10000000) return dp[mask][node];
    int ans = -10000000;
    for (int i = 0; i < n; i++) {
        if (mask & (1<<i)) continue;
        if (i == node) continue;
        int new_ans = g[node][i] + dfs(i, mask | (1<<i)); // modify this node bit to 1
        ans = max(ans, new_ans);
    }
    dp[mask][node] = ans;
    return ans;
}

int main() {
    cin >> n;
    ALL_VISITED = (1<<n)-1; // 2^n - 1
    g.assign(n, vector<int> (n,-10000000));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    dp.assign((1<<n), vector<int> (n, -10000000));

    int tmp = dfs(0,(1<<0)); // start at node 0
    cout << tmp;
}

// after normal dfs, we have to improve runtime
// backtrack
// branch and bound
