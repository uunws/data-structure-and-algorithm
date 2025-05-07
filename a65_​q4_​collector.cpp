#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <set>
using namespace std;

int n,k;

map<int,int> price;
map<int,vector<int>> book;

bool all_visit(vector<int> &vst) {
    for (auto & x : vst) {
        if (x==0) return false;
    }
    return true;
}

int find_worth(vector<int> &vst,vector<int> &already_choose) {
    // return i collection
    int ret = 0;
    int res = INT_MAX;
    for (int i = 0; i < k; i++) {
        if (already_choose[i] == 1) continue;
        int p = price[i];
        int cnt = 0;
        for (auto & x : book[i]) {
            if (vst[x] == 0) cnt++;
        }
        if (cnt == 0) continue;
        int rt = p/cnt;
        if (rt < res) {
            res = rt;
            ret = i;
        }
    }
    return ret; // the collection that have min price/number of node that can fill
}

void fill(vector<int> &vst, int select) {
    for (auto & x : book[select]) {
        vst[x] = 1;
    }
}

int main() {
    cin >> n >> k;
    // แต่ละชุดมีลำดับหมายเลขชุด 0->k
    for (int i = 0; i < k; i++) {
        int p;
        cin >> p;
        price[i] = p;
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int x;
            cin >> x;
            x--;
            book[i].push_back(x);
        }
    }
    vector<int> vst(n,0);
    vector<int> already_choose(k,0);
    int ans = 0;
    while (!all_visit(vst)) {
        // we choose the one with the min ratio
        // ratio = price/number of book that we can fill from choosing this collection
        int choose = find_worth(vst,already_choose);
        // cout << choose << endl;
        already_choose[choose] = 1;
        fill(vst,choose);
        ans += price[choose];
    }
    cout << ans;
}