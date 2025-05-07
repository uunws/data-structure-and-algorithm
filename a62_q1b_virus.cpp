#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> re(vector<int> v, int l, int r){
    vector<int> tmp = v;
    while (l < r) {
        swap(tmp[l++], tmp[r--]);
    }
    return tmp;
}

bool check_virus(vector<int> v, int start, int stop) {
    if (stop - start == 1) {
        if ((v[start] == 0 && v[stop] == 1)) {
            return true;
        }
        return false;
    }
    int mid = (start+stop)/2;
    return (check_virus(v, start, mid)||check_virus(re(v, start, mid), start, mid)) && check_virus(v, mid+1, stop);
}

int main() {
    int n, k;
    cin >> n >> k;
    int p = pow(2, k);
    for (int i = 0; i < n; i++) {
        vector<int> v(p);
        for (int j = 0; j < p; j++) {
            cin >> v[j];
        }
        // check is it virus แบ่งแล้ว ต้องเป็น 01 ไม่ก้ 10 เท่านั้น
        // แบ่งครึ่งไปเรื่อยๆ
        bool ans = check_virus(v, 0, v.size()-1);
        if (ans) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }  
    }
}