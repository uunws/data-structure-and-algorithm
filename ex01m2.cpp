#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge_count(vector<int> &v, int start, int m, int stop,int &cnt, vector<int> &tmp) {
    int bi = start; // index of B
    int ci = m + 1; // index of C
    for (int i = start; i <= stop; i++) {
        if (ci > stop) { // C หมดแล้ว
            tmp[i] = v[bi++];
            continue;
        }
        if (bi > m) { // B หมดแล้ว
            tmp[i] = v[ci++]; 
            continue;
        }
        if (v[bi] <= v[ci]) {
            tmp[i] = v[bi++];
        } else {
            tmp[i] = v[ci++];
            cnt+=(m-bi+1); 
            // cout << stop << " " << bi << endl;
        }
    }
    for (int i = start; i <= stop; i++) v[i] = tmp[i];
}

void merge_sort(vector<int> &v, int start, int stop, int &cnt, vector<int> &tmp) {
    if (start < stop) {
        int m = (start + stop) / 2;
        merge_sort(v, start, m, cnt, tmp);
        merge_sort(v, m + 1, stop, cnt, tmp);
        merge_count(v, start, m, stop, cnt, tmp);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    // merge sort
    // divided into 2 subarray (recur)
    // merge + count : if element from rightsub is smaller than element from leftsub, 
    // all the leftsub (after that leftsub element) is inversion of right sub
    int cnt = 0;
    int start = 0;
    int stop = n - 1;
    vector<int> tmp(n);
    merge_sort(v, start, stop, cnt, tmp);
    cout << cnt;
}