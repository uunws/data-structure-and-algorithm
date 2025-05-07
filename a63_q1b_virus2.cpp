#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool check_virus(vector<int> &v, int start, int stop) {
    if (start < stop) {
        int mid = (start+stop)/2;
        int cnt1 = 0; int cnt2 = 0;
        for (int i = start; i <= mid; i++) {
            if (v[i] == 1) cnt1++;
        }
        for (int i = mid+1; i <= stop; i++) {
            if (v[i] == 1) cnt2++;
        }
        if (abs(cnt1 - cnt2) > 1) return false;
        return check_virus(v, start, mid) && check_virus(v, mid+1, stop);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    int p = pow(2, k);
    for (int i = 0; i < n; i++) {
        vector<int> v(p);
        for (int j = 0; j < p; j++) {
            cin >> v[j];
        }
        bool ans = check_virus(v, 0, v.size()-1);
        if (ans) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}