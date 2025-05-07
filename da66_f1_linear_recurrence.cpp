#include <iostream>
#include <vector>
using namespace std;

int recur(vector<int> &table, int n, int k, vector<int> v_c, vector<int> v_a) {
    if (n < k) return v_a[n];
    if (table[n] > -1) {
        return table[n];
    }
    int res = 0;
    for (int i = 0; i < k; i++) {
        res += ((v_c[i]%32717) * recur(table, n-i-1, k, v_c, v_a))%32717;
    }
    table[n] = res%32717;
    return res%32717;
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<int> v_c(k); // 1-k
    vector<int> v_a(k); // 0-k-1
    for (int i = 0; i < k; i++) {
        cin >> v_c[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> v_a[i];
    }
    vector<int> table(n+10, -1); // เก็บ R(n-x) mod k
    cout << recur(table, n, k, v_c, v_a);
}
