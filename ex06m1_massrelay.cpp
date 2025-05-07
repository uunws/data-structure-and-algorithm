#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n,m,q;
vector<vector<int>> v;
vector<int> p;
vector<int> s;

int find_num_set() {
    int cnt = 0;
    for (auto & pi : p) {
        // อยากรู้ว่ามีกี่ cc นับจำนวน -1
        if (pi == -1) {
            cnt++;
        }
    }
    return cnt;
}

int findset(int x) {
    if (p[x] == -1) return x;
    p[x] = findset(p[x]);
    return p[x];
}

void unionf(int x, int y) {
    int s1 = findset(x);
    int s2 = findset(y);
    if (s[s1] > s[s2]) {
        p[s2] = s1;
        s[s1] = s[s1] + s[s2];
    } else {
        p[s1] = s2;
        s[s2] = s[s1] + s[s2];
    }
}

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int a,b,w;
        cin >> a >> b >> w;
        v.push_back({w,a,b});
    }
    sort(v.begin(), v.end());
    vector<int> cc(n, 1000000); // i cc -> min length of edge
    // assign ค่า max น้อยเกิน ได้ 30% !!!!!
    p.assign(n, -1);
    s.assign(n, 1);
    for (auto & subvec : v) {
        int w = subvec[0];
        int a = subvec[1];
        int b = subvec[2];
        if (findset(a) != findset(b)) {
            // ถ้าอยู่คนละset รวมcomponent แล้วก็ เอา len ไปใส่
            unionf(a,b);
            int num_of_set = find_num_set();
            cc[num_of_set] = min(cc[num_of_set], w);
        }
    }
    for (int i = 0; i < q; i++) {
        int d;
        cin >> d;
        cout << cc[d] << endl;
    }
}
