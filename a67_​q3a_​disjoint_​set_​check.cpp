#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    int n,q;
    cin >> n >> q;
    while (q--) {
        vector<int> p(n);
        vector<int> size(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            if (p[i] != -1) {
                p[i]--;
            } else {
                size[i] = 1;
            }
        }
        // case 0 0 : detect a cycle
        // เจอปมที่หาไปแล้วที่ไม่ใช่ parent
        vector<bool> vst(n, false);
        int idx;
        bool isCycle = false;
        vector<bool> mem(n, false);
        for (int i = 0; i < n && !isCycle; i++) {
            if (vst[i]) continue;
            idx = i;
            set<int> s;
            while (p[idx] != -1) { // ยังไม่ใช่ปมราก
                vst[idx] = true;
                s.emplace(idx);
                if (s.find(p[idx]) != s.end()) { // detect a cycle
                    isCycle = true;
                    break;
                }
                idx = p[idx];
            }
            if (p[idx] == -1) { // if end while loop because found root
                for (auto & x : s) {
                    if (mem[x] == false) { size[idx]++; mem[x] = true; }
                }
            }
        }
        if (isCycle) {
            cout << "0 0" << "\n";
        } else {
            cout << "1 " << *max_element(size.begin(), size.end()) << "\n";
        }
    }
}