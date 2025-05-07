#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int countOne(vector<int> &v, int start, int stop) {
    int cnt = 0;
    for (int i = start; i <= stop; i++) {
        cnt += v[i];
    }
    return cnt;
}

bool virus(vector<int> &v, int start, int stop) {
    int mid = (start+stop)/2;
    int cnt_l = countOne(v, start, mid);
    int cnt_r = countOne(v, mid+1, stop);
    if (abs(cnt_l-cnt_r) > 1) return false;
    if (stop-start==3) {
        if (abs(cnt_l-cnt_r) <= 1) return true;
        return false;
    }
    return virus(v, start, mid) && virus(v, mid+1, stop);
}

int main() {
    int n, k;
    cin >> n >> k;
    int p = pow(2, k);
    for (int i = 0; i < n; i++) {
        vector<int> v(p);
        for (int j = 0; j < p; j++) {
            cin >> v[j];
        }
        if (virus(v, 0, p-1)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}