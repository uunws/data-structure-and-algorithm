#include <iostream>
#include <vector>
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
    vector<vector<int>> arr(n+1 , vector<int>(n+1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    int a = n;
    int b = m;
    int cnt = n-1;
    vector<int> path;
    while (a != 0) {
        int op1 = arr[a-1][b];
        int op2 = arr[a-1][b-w[cnt]] + v[cnt];
        if (op2 == arr[a][b]) {
            path.push_back(a);
            b = b - w[cnt];
        }
        a--;
        cnt--;
    }
    cout << path.size() << endl;;
    for (auto & x : path) {
        cout << x << " ";
    }
}