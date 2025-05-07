#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    int n,d;
    cin >> n >> d;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int step = v[v.size()-1]/d;
    int curr = step;
    while (true) {
        int day = 1;
        auto it = upper_bound(v.begin(), v.end(), curr);
        if (it != v.begin()) it--;
        curr = (curr < v[0])? 0 : *it;
        bool flag = false;
        // cout << "-----" << step << "-----" << endl;
        while (curr < v[v.size()-1] && step < v[v.size()-1]) {
            // cout << curr << endl;
            int next = curr + step;
            auto it = upper_bound(v.begin(), v.end(), next);
            if (it == v.begin()) {
                flag = true;
                break;
            } 
            if (it != v.begin()) it--;
            if (it == v.end()) break;
            if (*it == curr) {
                flag = true;
                break;
            }
            curr = *it;
            day++; 
        }
        if (!flag && day <= d) {
            cout << step << " " << day;
            return 0;
        } else {
            // cout << "---------" << endl;
            step++;
            curr = step;
        }
    } 
}