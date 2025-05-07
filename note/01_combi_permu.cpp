// permu : ลำดับมีผล, combi : ลำดับไม่มีผล

// combi
void combi(int n, vector<int> &sol, int len) {
    if (len < n) {
        sol[len] = 0; // ใส่ 0 เข้าไป (ช่องที่ len)
        combi(n, sol, len+1); // recur วน 0 ก่อน
        sol[len] = 1; // ใส่ 1 เข้าไป (ช่องที่ len)
        combi(n, sol, len+1);
    } else {
        for (int i = 0; i < n; i++) {
            cout << sol[i] << " "; // คำตอบที่มีความยาว = n
        }
        cout << endl;
    }
}
// 0 0 0
// 0 0 1
// ...
// 1 1 1

// permu
void permu(int n, vector<int> &sol, int len, vector<bool> &used, int k) {
    if (len < k) { // permu of k items from n items
        for (int i = 1; i <= n; i++) { // เลขที่จะเอามาสับเปลี่ยน
            if (used[i] == false) { // กำหนกขนาดvectorตั้งต้น
                used[i] = true; // mark ว่า ใช้แล้ว
                sol[len] = i; // กำหนกขนาดvectorตั้งต้น
                permu(n, sol, len+1, used);
                used[i] = false; // mark กลับ (backtracking)
            }
        }
    } else {
        for (auto &x : sol) cout << x;
        cout << endl;
    }
}
// 123
// 132
// 213
// 231
// 312
// 321