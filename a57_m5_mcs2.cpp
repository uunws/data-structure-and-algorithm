#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int get_sum(vector<int> &prefix_sum, int l, int r) {
    if (l == 0) return prefix_sum[r]; 
    return prefix_sum[r] - prefix_sum[l-1];
} 

int find_max_sum(vector<int> &v, int start, int stop, vector<int> &prefix_sum) {
    if (start == stop) return v[start];
    int m = (start+stop)/2;
    int r1 = find_max_sum(v, start, m, prefix_sum);
    int r2 = find_max_sum(v, m+1, stop, prefix_sum);
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

int find_min_sum(vector<int> &v, int start, int stop, vector<int> &prefix_sum) {
    if (start == stop) return v[start];
    int m = (start+stop)/2;
    int r1 = find_min_sum(v, start, m, prefix_sum);
    int r2 = find_min_sum(v, m+1, stop, prefix_sum);
    int min_sum_left = get_sum(prefix_sum, m, m);
    for (int i = start; i <= m-1; i++) {
        min_sum_left = min(min_sum_left, get_sum(prefix_sum, i, m));
    }
    int min_sum_right = get_sum(prefix_sum, m+1, m+1);
    for (int i = m+2; i <= stop; i++) {
        min_sum_right = min(min_sum_right, get_sum(prefix_sum, m+1, i));
    }
    int r3 = min_sum_left + min_sum_right;
    return min({r1, r2, r3});
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    bool not_less_than_zero = false;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] >= 0) not_less_than_zero = true;
    }
    if (!not_less_than_zero) {
        sort(v.begin(), v.end());
        cout << v[n-1] << endl;
        return 0;
    }
    // find max of normal case
    // find min of normal case
    // find max of edge case : all sum - min
    vector<int> prefix_sum(n);
    prefix_sum[0] = v[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + v[i];
    }
    // all sum = last prefix_sum
    int max_normal = find_max_sum(v, 0, n-1, prefix_sum);
    // cout << max_normal << endl;
    int min_normal = find_min_sum(v, 0, n-1, prefix_sum);
    // cout << min_normal << endl;
    int max_edge = prefix_sum[n-1] - min_normal;
    // cout << max_edge << endl;
    cout << max(max_normal, max_edge);
}