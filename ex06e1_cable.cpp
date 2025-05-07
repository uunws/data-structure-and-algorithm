#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v; // w, i, j
vector<int> p;
vector<int> S; // size of tree

int findset(int x) {
    if (p[x]==-1) return x;
    p[x] = findset(p[x]);
    return p[x];
}

void union_func(int x,int y) {
    int s1 = findset(x); // root of x
    int s2 = findset(y); // root of y
    if (S[s1] > S[s2]) {
        p[s2] = s1;
        S[s1] = S[s1] + S[s2];
    } else {
        p[s1] = s2;
        S[s2] = S[s1] + S[s2];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) { // i=0
        for (int j = 0; j < n-i-1; j++) { // 4-0-1=3
            int w;
            cin >> w;  // i<->j
            v.push_back({w,i,i+j+1});
        }
    }
    // create disjoint set (store set as tree)
    p.assign(n, -1);
    S.assign(n, 1);
    int ans = 0;
    sort(v.begin(), v.end()); // sort (in weight order)
    // every pair of node
    for (auto & subvec : v) {
        int w = subvec[0];
        int x = subvec[1];
        int y = subvec[2];
        if (findset(x) != findset(y)) {
            ans += w;
            union_func(x,y); // union set by change pointer y
        }
    }
    cout << ans;
}