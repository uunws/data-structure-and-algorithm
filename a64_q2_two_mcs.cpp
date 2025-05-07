#include <iostream>
#include <vector>
using namespace std;

// simple kadane algo
int recur2(vector<int> &v, int start, int stop) {
    int res = v[start];
    int maxEnd = v[start];
    for (int i = start + 1; i < stop; i++) {
        maxEnd = max(maxEnd + v[i], v[i]);
        res = max(res, maxEnd);
    }
    return res;
}

int recur1(vector<int> &v) {
    int res = v[0]; // max sum
    int maxEnd = v[0];
    int begin = 0;
    int begin_tmp = 0;
    int end = 0;
    for (int i = 1; i < v.size(); i++) {
        // end = i;
        if (v[i] > maxEnd + v[i]) {
            begin_tmp = i;
        }
        maxEnd = max(maxEnd + v[i], v[i]);
        if (maxEnd > res) {
            begin = begin_tmp; // ตนที่subarrayนี้เริ่ม
            end = i; // subarray ที่ดีที่สุด จบตรงนี้
        }
        res = max(maxEnd, res);
    }
    return res + max(recur2(v, 0, begin), recur2(v, end+1, v.size())); // recur2 ไม่รวมindex stop
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << recur1(v);
}