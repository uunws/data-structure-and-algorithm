#include <iostream>
#include <vector>
#include <set>
using namespace std;

void permu(set<string> &v, int len, int n, string s) {
        if (n < len) {
            permu(v, len, n + 1, s+"0");
            permu(v, len, n + 1, s+"1");
        } else {
            v.insert(s);
        }
    }

int main() {
    int n, k;
    cin >> n >> k;
    set<string> v;
    // permu of 0, 1 in n 
    permu(v, n, 0, "");
    for (auto & x : v) {
        int count = 0;
        for (auto & y : x) {
            if (y == '1') {
                count++;
            }
            if (y == '0') {
                count = 0;
            }
            if (count == k) {
                cout << x << endl;
                break;
            }
        }
    }
}