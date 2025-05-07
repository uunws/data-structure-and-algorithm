#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> re(vector<int>v, int start, int stop) {
    while (start < stop) {
        swap(v[start], v[stop]);
        start++; stop--;
    }
    return v;
}

bool virus(vector<int>&v, int start, int stop) {
    if (stop-start==1) {
        if (v[start] == 0 && v[stop] == 1) return true;
        // if (v[start] == 1 && v[stop] == 0) return true;
        return false; 
    }
    int mid = (start+stop)/2;
    auto re_v = re(v, start, mid);
    return (virus(v, start, mid) && virus(v, mid+1, stop)) || (virus(re_v, start, mid) && virus(v, mid+1, stop));
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
        if (k == 1) {
            if (v[0] != 0 || v[1] != 1) {
                cout << "no" << endl;
            } else {
                cout << "yes" << endl;
            }
        } else {
            int start = 0;
            int stop = v.size() - 1;
            int flag = virus(v, start, stop);
            if (flag) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }
}