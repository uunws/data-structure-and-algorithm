#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector<vector<int>> arr(n+1, vector<int> (m+1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    int res = m;
    set<int> path;
    for (int i = n; i > 0; i--) {
        // if (arr[i][res] != arr[i-1][res-w[i-1]] + v[i-1]) {
        //     path.insert(i);
        //     res-=w[i-1];
        // } 
        if (arr[i][res] == arr[i-1][res]) {
            continue; // ไม่ทำอะไร
        } else {
            path.insert(i);
            res-=w[i-1];
        }
    }
    cout << path.size() << endl;
    for (auto&x : path) {
        cout << x << " ";
    }
}