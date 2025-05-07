#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> cnt(4,0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        cnt[v[i]]++;
    }
    vector<vector<int>> misplaced(4, vector<int>(4,0));
    int idx = 0;
    for (int i = 1; i <4; i++) {
        while (cnt[i]--) {
            misplaced[i][v[idx++]]++;
        }
    }
    // we get misplaced[1][2] 2 that was in the wrong place (in 1 zone)
    // there are two way swap that we have to consider
    // the first is direct swap which in each pair is min(misplaced[1][2], misplaced[2][1])
    // the second one is cycle swap which is the rest of node that have to switch as cycle
    // cycle swap can count by (remain_misplaced/3)*2 : we need 2 swap to swap as cycle
    int direct_swap = 0;
    for (int i = 1; i < 4; i++) {
        for (int j = i+1; j < 4; j++) {
            int res = min(misplaced[i][j], misplaced[j][i]);
            misplaced[i][j] -= res;
            misplaced[j][i] -= res;
            direct_swap += res;
        }
    }
    int remain_misplaced = 0;
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            if (i != j) remain_misplaced += misplaced[i][j];
        }
    }
    int cycle_swap = 2 * (remain_misplaced/3);
    cout << direct_swap + cycle_swap << endl;
}