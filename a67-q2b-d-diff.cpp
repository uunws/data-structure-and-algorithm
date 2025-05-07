#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    long long n,d;
    cin >> n >> d;
    vector<long long> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int diff = abs(A[i] - A[j]);
            if (diff <= d) cnt++;
        }
    }
    cout << cnt;
}