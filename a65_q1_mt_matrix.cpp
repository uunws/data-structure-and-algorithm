#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int n;
vector<vector<int>> v;
int my_func(ll r, ll c, int cnt, bool neg) {
    ll size = 1LL << (n-cnt);
    if (n-cnt==1) {
        if (neg) { // neg = true : ติดลบ
           return -v[r][c]; 
        }
        return v[r][c];
    }
    ll half_size = size/2;
    if (r < half_size && c < half_size) { // Q1
        return my_func(r, c, cnt+1, neg);
    }
    if (r < half_size && c >= half_size) { // Q2
        return my_func(c - half_size, r, cnt+1, neg);
    }
    if (r >= half_size && c < half_size) { // Q3
        return my_func(r - half_size, c, cnt+1, !neg);
    }
    if (r >= half_size && c >= half_size) { // Q4
        return my_func(c - half_size, r - half_size, cnt+1, !neg);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m;
    cin >> n >> m;
    int a, b, c ,d;
    cin >> a >> b >> c >> d;
    // long long power = (1LL << n);
    v = {{a,b},{c,d}}; // 0-base
    for (int i = 0; i < m; i++) {
        ll r, c;
        cin >> r >> c; // 1-base
        r-=1;
        c-=1;
        cout << my_func(r, c, 0, false) << "\n"; // 0-base
    }
}

