#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n;
    cin >> n;
    // vector<vector<int>> M(n, vector<int> (n));
    vector<int> deg(n); // index i : deg of edge i
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                deg[i]++;
            }
        }
    }
    sort(deg.begin(), deg.end());
    vector<int> ans(deg.back() + 1, 0);
    for (auto & x : deg) {
        ans[x]++;
    }
    for (auto & x : ans) {
        cout << x << " ";
    }
}