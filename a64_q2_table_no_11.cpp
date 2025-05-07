#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long m = 100000007;
    long long n;
    cin >> n;
    long long prev0 = 3;
    long long prev1 = 7;
    if (n == 1) {
        cout << "3" << endl;
        return 0;
    }
    for (int i = 2; i < n; i++) {
        long long res = prev0%m + (prev1*2)%m;
        prev0 = prev1;
        prev1 = res;
    }
    cout << prev1%m;
}