#include <bits/stdc++.h>

using namespace std;

// 0 1 0 0 1
// state 0 : if input = 0, go to state 1
// state 1 : if input = 1, go to state 2
// state 2 : if input = 0, go to state 3
// state 3 : if input = 0, go to state 4
// state 4 : if input = 1, invalid

int n,k;
vector<int> forbid;
vector<int> c;

// vector<vector<int>> tmp;
int ans = INT_MIN;
void combi(vector<int> &sol, int len, int state, int prev, int sum) { // check state until k-1 that we decided
    // cout << state << endl;
    int next_state_bit = forbid[state];
    bool forbid_zero = false;
    bool forbid_one = false;
    if (state == k-1) {
        // can choose only one bit
        if (forbid[state] == 0) {
            forbid_zero = true;
        } else {
            forbid_one = true;
        }
    }
    if (len < n) {
        if (!forbid_zero) {
            sol[len] = 0;
            combi(sol,len+1,(next_state_bit == 0)? state+1 : 0,0,sum); // has to fallback to state 0 too
        }
        if (!forbid_one && prev != 1) { // consider prev because we cannot select bit that next to each other
            sol[len] = 1;
            combi(sol,len+1,(next_state_bit == 1)? state+1 : 0,1,sum+c[len]);
        }
    } else {
        // for (auto & x : sol) cout << x << " ";
        // cout << endl;
        // tmp.push_back(sol);
        ans = max(ans,sum);
    }
}

int main() {
    cin >> n >> k;
    c.assign(n,0);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    forbid.assign(n,0);
    for (int i = 0; i < k; i++) {
        cin >> forbid[i];
    }
    vector<int> sol(n);
    combi(sol,0,0,-1,0);
    // int ans = INT_MIN;
    // for (auto & x : tmp) {
    //     int sum = 0;
    //     for (int i = 0; i < n; i++) {
    //         if (x[i]==1) sum += c[i]; 
    //     }
    //     ans = max(ans,sum);
    // }
    cout << ans;
}