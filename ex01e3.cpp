#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (x < v[0]) {
            cout << "-1" << endl; 
        } else {
            int min = 0;
            int max = v.size() - 1;
            while (min < max) {
                int mid = (min+max)/2;
                if (v[mid] < x) min = mid + 1;
                if (v[mid] >= x) max = mid;
            }
            if (v[max] > x) {
                cout << v[max - 1] << endl;
            } else {
                cout << v[max] << endl;
            }
        }
        
    }
}