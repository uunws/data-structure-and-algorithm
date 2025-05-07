#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    vector<int> ques;
    for (int i = 0; i < q; i++) {
        int id;
        cin >> id;
        ques.push_back(id);
    }
    sort(v.begin(), v.end());
    vector<int> res;
    vector<int> num;
    int freq = 0;
    for (auto & x : v) {
        freq += x.second;
        res.push_back(freq);
        num.push_back(x.first);
    }
    vector<int> ans;
    for (auto & x : ques) {
        auto it = lower_bound(res.begin(), res.end(), x);
        if (it != res.end()) ans.push_back(num[it - res.begin()]);
    }
    for (auto & x : ans) {
        cout << x << endl;
    }
}