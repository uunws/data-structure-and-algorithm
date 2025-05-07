#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <climits>
using namespace std;

double W;
int n;
vector<double> v;
vector<double> w;
// priority_queue<vector<double>, vector<vector<double>>> pq;
vector<vector<double>> tmp;

double ans = 0;

void recur(int idx, double remain, double sum_price) {
    if (idx == 0 || remain == 0.0) { // ของที่เหลือหมด หรือว่า เลือกเต็มถุงแล้ว (ไม่เหลือพื้นที่ให้ใส่แล้ว)
        ans = sum_price;
        return;
    }
    if (remain >= tmp[idx][2]) {
        recur(idx-1,remain-tmp[idx][2],sum_price+tmp[idx][1]);
    } else {
        // double res = remain / tmp[idx][2]; // อัตราส่วนเพื่อหาราคา
        recur(idx-1,0.0,sum_price + tmp[idx][1]*(remain / tmp[idx][2])); // remain ใส่0 ได้เลย เพราะเปนการเลือกเศษส่วนให้เต็ม
    }
}

int main() {
    cin >> W >> n;
    v.assign(n,0.0);
    for (int i = 0; i < n; i++) {
        cin >> v[i]; // price
    }
    w.assign(n,0.0);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    // select item with most price/weight first
    tmp.assign(n, vector<double>(3,0.0));
    for (int i = 0; i < n; i++) {
        tmp[i] = {v[i]/w[i], v[i], w[i]};
    }
    sort(tmp.begin(), tmp.end()); // max value is in the back
    recur(n-1,W,0.0); // idx (number of item that can choose), remain, sum_price
    cout << fixed << setprecision(4) << ans;
}