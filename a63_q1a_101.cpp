#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m = 100000007;
    long long n;
    cin >> n;
    int prev_prev0 = 1;
    int prev0 = 2;
    int prev1 = 2;
    for (long long i = 2; i < n; i++) {
        int tmp = prev0;
        prev0 = prev0%m + prev1%m;
        prev1 = prev1%m + prev_prev0%m;
        prev_prev0 = tmp;
    }
    cout << (prev0%m + prev1%m)%m;
}