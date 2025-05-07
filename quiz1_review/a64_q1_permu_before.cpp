#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void permu(map<int, set<int>> &con, int n, int len, vector<int> &sol, vector<bool> &used) {
    if (len < n) {
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            bool flag = true;
            if (con.find(i) != con.end()) { // เจอ b
                for (auto &x : con[i]) {
                    // ไม่เจอ a
                    if (find(sol.begin(), sol.end(), x) == sol.end()) {
                        flag = false;
                        break;
                    } 
                }
            }
            if (flag) {
                used[i] = true;
                sol.push_back(i);
                permu(con, n, len+1, sol, used);
                sol.pop_back();
                used[i] = false;
            }
        }
    } else {
        if (sol.size() == n) {
            for (auto & x : sol) cout << x << " ";
            cout << "\n";
        } 
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    map<int, set<int>> con;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        con[b].insert(a);
    }
    vector<int> sol;
    vector<bool> used(n);
    permu(con, n, 0, sol, used);
}