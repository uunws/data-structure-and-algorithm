#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool all_one(vector<int> &check) {
    for (auto &x : check) {
        if (x != 1) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; // n = จนวัน m = จนคน
    cin >> n >> m;
    vector<vector<int>> v(m); // แต่ละคนมาวันไหนบ้าง
    vector<int> persons(m);
    for (int i = 0; i < m; i++) {
        persons[i] = i;
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            v[i].push_back(y-1);
        }
    }
    // vector เก็บ index ของแต่ละวัน: days
    // check ว่า 1 หมดยัง
    int min = 1000;
    do 
    {
        vector<int> check(n, 0);
        int cnt = 0;
        for (auto & person : persons) {
            for (auto & d : v[person]) {
                check[d] = 1;
            }
            cnt++;
            if (all_one(check)) {
                if (cnt < min) min = cnt; break;
            }
        } 
    }
    while (next_permutation(persons.begin(), persons.end()));
    cout << min;
}