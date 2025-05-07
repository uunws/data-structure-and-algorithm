#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int get_sum(vector<int> &prefix_sum, int l, int r) {
    return prefix_sum[r] - prefix_sum[l-1];
}

int mss(vector<int> &v, int start, int stop, vector<int> &prefix_sum) {
    if (start == stop) return v[start];
    int m = (start+stop)/2;

    int r1 = mss(v, start, m, prefix_sum);
    int r2 = mss(v, m+1, stop, prefix_sum);

    int max_sum_left = get_sum(prefix_sum, m, m);
    for (int i = start; i <= m-1; i++) {
        max_sum_left = max(max_sum_left, get_sum(prefix_sum, i, m));
    }

    int max_sum_right = get_sum(prefix_sum, m+1, m+1);
    for (int i = m+2; i <= stop; i++) {
        max_sum_right = max(max_sum_right, get_sum(prefix_sum, m+1, i));
    }

    int r3 = max_sum_left + max_sum_right;
    return max({r1, r2, r3});
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> prefix_sum(n);
    prefix_sum[0] = v[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + v[i];
    }
    cout <<  mss(v, 0, n-1, prefix_sum);
}