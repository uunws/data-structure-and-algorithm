#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> res(k,vector<int>(3));
    for (int i = 0; i < k; i++) {
        int d,e,l;
        cin >> d >> e >> l;
        d--;
        l--;
        res[i] = {d,e,l};
    }
    sort(res.begin(), res.end());

    queue<int> stock;
    queue<int> waiting;

    for (int i = 0; i < k; i++) {
        vector<int> curr = res[i];
        // int date = curr[0];
        int type = curr[1];
        int label = curr[2]; // label mean plan and store
        // there is only one product
        if (type == 0) { // A
            if (waiting.empty()) {
                stock.push(label);
                cout << "0" << endl;
            } else {
                int s = waiting.front();
                waiting.pop();
                cout << s+1 << endl;
            }
        } else { // B
            if (stock.empty()) {
                waiting.push(label);
                cout << "0" << endl;
            } else {
                int p = stock.front();
                stock.pop();
                cout << p+1 << endl;
            }
        }
    }
}