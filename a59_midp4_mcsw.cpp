#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int get_sum(vector<int> &prefix_sum, int l, int r, int w) {
    if (l!=0) return prefix_sum[r] - prefix_sum[l-1];
    return prefix_sum[r];
}

int mss(vector<int> &v, int start, int stop, vector<int> &prefix_sum, int w) {
    if (start == stop) {
        return v[start];
    }
    int m = (start+stop)/2;
    int r1 = mss(v, start, m, prefix_sum, w);
    int r2 = mss(v, m+1, stop, prefix_sum, w);
    int max_sum_left = get_sum(prefix_sum, m, m, w);
    for (int i = start; i <= m-1; i++) {
        if (m-i < w) {
            max_sum_left = max(max_sum_left, get_sum(prefix_sum, i, m, w));
        }
    }
    int max_sum_right = get_sum(prefix_sum, m+1, m+1, w);
    for (int i = m+2; i <= stop; i++) {
        if (i-(m+2) < w) {
            max_sum_right = max(max_sum_right, get_sum(prefix_sum,m+1, i, w));
        }
    }
    int r3 = max_sum_left + max_sum_right;
    return max({r1,r2,r3});
}

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> v(n);
    bool check = false;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] > 0) check = true;
    }
    if (!check) {
        sort(v.begin(), v.end());
        cout << v[v.size()-1];
        return 0;
    }
    vector<int> prefix_sum(n);
    prefix_sum[0] = v[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + v[i];
    }
    cout << mss(v, 0, v.size()-1, prefix_sum, w);
}

