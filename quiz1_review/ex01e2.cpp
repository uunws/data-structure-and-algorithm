#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int get_sum(vector<int> &prefix, int l, int r) {
    if (l==0) return prefix[r];
    return prefix[r] - prefix[l-1];
}

int mss(vector<int> &v, vector<int> &prefix, int start, int stop) {
    if (start == stop) return v[start];
    int m = (start+stop)/2;
    
    int r1 = mss(v, prefix, start, m);
    int r2 = mss(v, prefix, m+1, stop);

    int max_sum_left = get_sum(prefix, m, m);
    for (int i = start; i <= m-1; i++) {
        max_sum_left = max(max_sum_left, get_sum(prefix, i, m));
    }

    int max_sum_right = get_sum(prefix, m+1, m+1);
    for (int i = m+2; i <= stop; i++) {
        max_sum_right = max(max_sum_right, get_sum(prefix, m+1, i));
    }

    int r3 = max_sum_left + max_sum_right;
    return max({r1, r2, r3});
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v[0];
    vector<int> prefix(n);
    prefix[0] = v[0];
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        prefix[i] = prefix[i-1] + v[i];
    }
    cout << mss(v, prefix, 0, n-1);
}