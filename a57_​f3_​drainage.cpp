#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,l;
    cin >> n >> l;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    // cout << "debug1" << endl;
    int start = arr[0];
    int stop = start + l-1;
    int last = arr[arr.size()-1];
    // cout << "debug2" << endl;
    int cnt = 1;
    while (stop <= last) {
        // cout << stop << endl;
        auto it = upper_bound(arr.begin(),arr.end(),stop);
        if (it == arr.end()) break;
        int after_stop = *it;
        stop = after_stop + l-1;
        cnt++;
    }
    cout << cnt;
}