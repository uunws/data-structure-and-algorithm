#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, a;
    cin >> n >> a;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < a; i++) {
        long long c;
        cin >> c;
        long long min = 0;
        long long max = 1000000000000;
        while (min < max) {
            long long res = n;
            long long mid = (min+max)/2;
            for (int i = 0; i < n; i++) {
                res += mid/t[i];
            }
            if (res < c) min = mid+1;
            if (res >= c) max = mid;
        }
        cout << max << endl;;
    }
    // algorithm : [t/T1] + [t/T2] + ... + [t/Ti] = c + 1 - 3 (ปัดลง)
    // min, max = [(c-3)/จน.chef, Tmax/(c-3)]
}