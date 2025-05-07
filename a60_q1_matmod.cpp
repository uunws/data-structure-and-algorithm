#include <iostream>
#include <vector>
using namespace std;

vector<int> mod(vector<int> v, int n, int k) {
    if (n == 1) {
        v[0] = v[0] % k;
        v[1] = v[1] % k;
        v[2] = v[2] % k;
        v[3] = v[3] % k;
        return v;
    }
    if (n % 2 == 0) {
        vector<int> tmp = mod(v, n/2, k);
        int v0 = (tmp[0]*tmp[0] + tmp[1]*tmp[2])%k;
        int v1 = (tmp[0]*tmp[1] + tmp[1]*tmp[3])%k;
        int v2 = (tmp[0]*tmp[2] + tmp[2]*tmp[3])%k;
        int v3 = (tmp[1]*tmp[2] + tmp[3]*tmp[3])%k;
        vector<int> ans;
        ans.push_back(v0);
        ans.push_back(v1);
        ans.push_back(v2);
        ans.push_back(v3);
        return ans;
    } else {
        vector<int> tmp = mod(v, n/2, k);
        int v0 = (tmp[0]*tmp[0] + tmp[1]*tmp[2])%k;
        int v1 = (tmp[0]*tmp[1] + tmp[1]*tmp[3])%k;
        int v2 = (tmp[0]*tmp[2] + tmp[2]*tmp[3])%k;
        int v3 = (tmp[1]*tmp[2] + tmp[3]*tmp[3])%k;
        int x0 = (v0*(v[0]%k)+v1*(v[2]%k))%k;
        int x1 = (v0*(v[1]%k)+v1*(v[3]%k))%k;
        int x2 = (v2*(v[0]%k)+v3*(v[2]%k))%k;
        int x3 = (v2*(v[1]%k)+v3*(v[3]%k))%k;
        vector<int> ans;
        ans.push_back(x0);
        ans.push_back(x1);
        ans.push_back(x2);
        ans.push_back(x3);
        return ans;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(4);
    cin >> v[0] >> v[1] >> v[2] >> v[3]; // a = x11, b = x12, c = x21, d = x22
    vector<int> ans = mod(v, n, k);
    for (auto & x : ans) cout << x << " ";
}