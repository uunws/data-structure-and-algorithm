#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <map>
#include <set>
using namespace std;

vector<vector<int>> ans;

void combi(int p, vector<int> &sol, int len) {
    if (len < p) {
        sol.push_back(0);
        combi(p,sol,len+1);
        sol.pop_back();
        sol.push_back(1);
        combi(p,sol,len+1);
        sol.pop_back();
    } else {
        ans.push_back(sol);
    }
}

int main() {
    int n,q_len,k;
    cin >> n >> q_len >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // seperate array into two part
    // in each part find choose 0,1,2 (for example if we have 4)
    // find two cases x+y<=k and x+y>=k (find min between these two cases)
    int m = v.size()/2; // 4/2
    int m1,m2;
    if (v.size()%2 == 1) {
        m1 = m;
        m2 = m+1;
    } else {
        m1 = m;
        m2 = m;
    }
    vector<pair<int,int>> v1;
    map<int,set<int>> v2;

    vector<int> sol1;
    combi(m1,sol1,0);
    vector<vector<int>> ch1 = ans;

    ans.clear();

    vector<int> sol2;
    combi(m2,sol2,0);
    vector<vector<int>> ch2 = ans;

    sort(v.begin(), v.end());

    for (vector<int> & x1 : ans) {
        int res = 0;
        int len = 0;
        for (int i = 0; i < x1.size(); i++) {
            if (x1[i] == 1) { // choose
                res += v[i];
                len++;
            }
        }
        v1.push_back({res,len});
    }
    for (vector<int> & x2 : ans) {
        int res = 0;
        int len = 0;
        for (int i = 0; i < x2.size(); i++) {
            if (x2[i] == 1) {
                res += v[m+i];
                len++;
            }
        }
       v2[len].insert(res);
    }
    int best_left = INT_MAX; // find min
    for (auto & x1 : v1) {
        int value = x1.first;
        int len = x1.second;
        int y = k - value;
        int rest = q_len-len;
        // เราต้องการตัวมากสุดที่<=y เราเลยไล่จากหลังมาหน้า และตัวที่มีจำนวน=rest เพื่อให้ผลรวมรวมเป็น m พอดี
        if (v2.find(rest) == v2.end()) continue;
        // auto it1 = lower_bound(v2[rest].begin(), v2[rest].end(), y);
        auto it1 = v2[rest].lower_bound(y);
        if (*it1 != y && it1 != v2[rest].begin() && it1 != v2[rest].end()) it1--;
        if (it1 != v2[rest].end()) best_left = min(best_left, abs(k - (value+*it1)));
    }
    int best_right = INT_MAX;
    for (auto & x2 : v1) {
        int value = x2.first;
        int len = x2.second;
        int y = k - value;
        int rest = q_len - len;
        // เราต้องการตัวน้อยสุดที่>=y เราเลยไล่จากหน้าไปหลัง
        if (v2.find(rest) == v2.end()) continue;
        // auto it2 = lower_bound(v2[rest].begin(), v2[rest].end(), y);
        auto it2 = v2[rest].lower_bound(y);
        if (it2 != v2[rest].end()) best_right = min(best_right, abs(k - (value+*it2)));
    }   
    cout << min(best_left, best_right); 
}