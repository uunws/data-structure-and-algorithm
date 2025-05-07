#include <iostream>

using namespace std;
int cnt = 0;
int recur(int n, int l, int r, int start, int stop) { 
    // binary search: count when l > start && r < stop 
    // ปรับl, r ให้เป็น 0-base
    if (l >= start && r <= stop) {
        cnt += n%2;
    }
    
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    int len = 0;
}