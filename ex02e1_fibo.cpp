#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int f2 = 0; // f(n-2)
    int f1 = 1; // f(n-1)
    for (int i = 2; i <= n; i++) { // เอาถึงแค่ตัวn
        int f = f1 + f2;
        f2 = f1;
        f1 = f;
    }
    cout << f1;
}