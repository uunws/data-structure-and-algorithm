#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, a;
    cin >> n >> a;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >>t[i];
    }
    for (int i = 0; i < a; i++) {
        ll c;
        cin >> c;
        ll min = 0;
        ll max = 1000000000000;
        while (min < max) {
            ll mid = (min+max)/2;
            ll sum = n;
            for (auto &x:t) {
                sum += mid/x;
            }
            if (sum < c) {
                min = mid+1;
            } else {
                max = mid;
            }
        }
        cout << max << endl;
    }
}