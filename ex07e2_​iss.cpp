#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int n;
set<vector<int>> path;

void recur(int sum, vector<int> &p, int len) {
    if (sum > n) return;
    if (len > n) return;
    if (sum < n) {
        for (int i = (p.empty())? 1 : p[p.size()-1] ; i <= n; i++) {
            if (n - sum+i < i) return; // end that path
            if (sum+i>n) return;
            p.push_back(i);
            recur(sum+i, p, len+1);    
            p.pop_back(); // อย่าลืม pop_back() ออกด้วย
            // หลังจาดเลือกตัวนั้นไปแล้ว เราต้องbacktrack เพื่อลอง option อื่นด้วย
        }
    }
    if (sum == n) {
        path.emplace(p);
    }
}

int main() {
    cin >> n;
    vector<int> tmp;
    recur(0,tmp,0);
    // for (auto & x : path) {
    //     for (auto & y : x) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }
    cout << path.size();
}