#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,e;
    cin >> n >> e;
    vector<vector<int>> g(n+1);
    vector<int> indeg(n+1, 0);
    for (int i = 0; i < e; i++) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b); // a->b
        indeg[b]++;
    }
    for (int i = 0; i < 5; i++) {
        bool flag = true;
        auto indeg1 = indeg; // copy indeg
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (indeg1[x] != 0) { // start node -> indeg must be 0
                flag = false;
            }
            for (auto & b : g[x]) {
                indeg1[b]--;
            }
        }
        if (flag) {
            cout << "SUCCESS" << endl;
        } else {
            cout << "FAIL" << endl;
        }
    }
}