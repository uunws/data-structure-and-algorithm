#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void permu(int n, map<int, set<int>> s, set<vector<int>> &ans, int len, vector<int> p, vector<bool> &visited) {
    if (len < n) {
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue; // ข้าม i นี้ไป
            bool flag = true;
            if (s.find(i) != s.end()) { // เจอ
                for (auto & x : s[i]) {
                    if (find(p.begin(), p.begin() + len, x) == p.begin() + len) { // ไม่เจอ -> หยุดrecur
                        flag = false;
                        // cout << "debug" << i << endl;
                        break;
                    }
                }
            }
            if (flag) {
                visited[i] = true;
                p[len] = i;
                permu(n, s, ans, len+1, p, visited);
                visited[i] = false;
            }
        }
    } else {
        ans.insert(p);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    map<int, set<int>> s;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        s[b].insert(a);
    }
    set<vector<int>> ans;
    vector<int> p(n);
    vector<bool> visited(n, false);
    permu(n, s, ans, 0, p, visited);
    for (auto & x : ans) {
        for (auto & y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
}