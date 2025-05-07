#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> p;
vector<int> S;

int findset(int x) {
    if (p[x]==-1) return x;
    p[x] = findset(p[x]);
    return p[x];
}

void unionf(int x, int y) {
    int s1 = findset(x);
    int s2 = findset(y);
    if (S[s1] > S[s2]) {
        p[s2] = s1;
        S[s1] = S[s1] + S[s2];
    } else {
        p[s1] = s2;
        S[s1] = S[s1] + S[s2];
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v; // w, x, y
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<vector<int>> mark(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (mark[i][j] == 0) {
                mark[i][j] = 1;
                mark[j][i] = 1;
                int res = c[i] ^ c[j];
                v.push_back({res, i, j});
            }
        }
    }
    p.assign(n,-1); // contain root
    sort(v.begin(), v.end(), greater<vector<int>>());
    // //
    // for (auto subvec : v) {
    //     cout << subvec[0] << " " << subvec[1] << " " << subvec[2] << endl;
    // }
    // //
    S.assign(n, 1);
    unsigned long long ans = 0;
    for (auto & x : v) {
        int w = x[0];
        int n1 = x[1];
        int n2 = x[2];
        if (findset(n1) != findset(n2)) {
            ans += w;
            unionf(n1, n2);
        }
    }
    cout << ans;
}