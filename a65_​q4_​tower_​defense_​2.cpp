#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m,k,w;
    cin >> n >> m >> k >> w;
    vector<int> p(m); // pos
    map<int,int> tmp;
    for (int i = 0; i < m; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<int> h(m); // hp
    for (int i = 0; i < m; i++) {
        cin >> h[i];
        tmp[p[i]] += h[i];
    }
    for (int i = 0; i < n && k != 0; i++) { // ไล่ทุกช่อง
        // ดูว่าช่องนั้นโจมตี monster ได้หรือไม่
        // ถ้าโจมตีได้ hpของmonsterนั้น--
        // ถ้า monster นั้น มี hp = 0 แล้ว ไม่ต้องพิจารณา
        // นับว่า hp ทั้งหมด เหลือเท่าไหร่ -> คำตอบ
        // ถ้า hp ลบได้ค่อยวางป้อม -> นับป้อม
        int left = max(0,i-w);
        int right = min(n-1,i+w);
        // หา monster ที่อยู่ระหว่าง left กับ right
        auto it1 = tmp.lower_bound(left);
        auto it2 = tmp.upper_bound(right); // ต้อง--
        bool flag = false;
        for (auto it = it1; it != it2; it++) {
            int pos = it->first;
            int hp = it->second;
            if (hp > 0) {
                tmp[pos]--;
                flag = true;
                break;
            }
        }
        if (flag) k--; // ลบก้ต่อเมื่อวาง tower ที่ตำแหน่งนั้น -> loop บน คือ loop ที่ไล่ว่าจะวางหรือไม่วาง tower
    }
    int ans = 0;
    for (auto & x : tmp) {
        ans += x.second;
    }
    cout << ans;
}