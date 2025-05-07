#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> start(n);
    for (int i = 0; i < n; i++) {
        cin >> start[i];
    }
    vector<int> end(n);
    for (int i = 0; i < n; i++) {
        cin >> end[i];
    }
    vector<vector<int>> res(n, vector<int> (2,0));
    for (int i = 0; i < n; i++) {
        res[i] = {end[i],start[i]};
    }
    sort(res.begin(), res.end()); // sort stop time จากน้อยไปมาก
    int curr_stop = res[0][0];
    int cnt = 1;
    for (int i = 1; i < n; i++) { // เลือกเฉพาะตัวที่ start time > stop time ของตัวก่อนหน้า
        if (res[i][1] >= curr_stop) { // เลือกได้
            cnt++;
            curr_stop = res[i][0]; // update stop time
        }
    }
    cout << cnt;
}