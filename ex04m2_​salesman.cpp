#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n,m;
vector<int> prefix_sum;
int sum_all = 0;

int find_min_path(int x, int y) {
    int diff = abs(prefix_sum[x]-prefix_sum[y]);
    return min(diff, sum_all-diff);
}

int find_min_way(int x, int y, int A, int B) {
    int way1 = find_min_path(x,y);
    int way2 = find_min_path(x,A) + find_min_path(B,y);
    int way3 = find_min_path(x,B) + find_min_path(A,y);
    return min({way1, way2, way3});
}

int main() {
    cin >> n >> m; // n : days m : seq
    vector<int> seq(m+1);
    for (int i = 0; i < m; i++) {
        cin >> seq[i];
    }
    seq[m] = seq[0]; // เดินวนกลับมา
    // store time as circular prefix_sum
    prefix_sum.assign(m+1,0);
    // prefix_sum[0] = 0;
    for (int i = 1; i <= m; i++) {
        int t;
        cin >> t;
        prefix_sum[i] = prefix_sum[i-1] + t;
        sum_all += t;
    }
    // there is two way to walk x->y or x->A->B->y
    // x->y choose min path (clockwise/counter-clockwise)
    // create func find_min_path (between clockwise/counter-clockwise)
    // find answer for each day
    for (int i = 0; i < n; i++) {
        int A,B;
        cin >> A >> B;
        int total_min = 0;
        for (int i = 0; i < m; i++) {
            int x = seq[i];
            int y = seq[i+1];
            // find_min_way func to find min way between x->y or x->A->B->y or x->B->A->y
            // between A and B use 0
            int min_way = find_min_way(x,y,A,B);
            // cout << x << " " << y << " " << min_way << endl;
            total_min += min_way;
        }
        cout << total_min << endl;
    }
}