#include <iostream>
#include <vector>
using namespace std;

bool checkSZero(vector<vector<int>> &v, int start_x, int stop_x, int start_y, int stop_y) {
    for (int i = start_x; i <= stop_x; i++) {
        for (int j = start_y; j <= stop_y; j++) {
            if (v[i][j] != 0) return false;
        }
    } 
    return true;
}

int checkPQR(int P, int Q, int R) {
    if (P == 0 || Q == 0 || R == 0) return 0;
    if (P == Q && P != 0) return P;
    if (Q == R && Q != 0) return Q;
    if (P == R && P != 0) return P;
    return 0;
}

int check_triforce(vector<vector<int>> &v, int start_x, int stop_x, int start_y, int stop_y) { // if not, return -1
    if (start_x == stop_x && start_y == stop_y)  return v[start_x][start_y]; 
    if (stop_x - start_x == 1 && stop_y - start_y == 1) {
        if (v[stop_x][stop_y] == 0 
        && v[start_x][start_y] != 0 
        && v[start_x][stop_y] != 0
        && v[stop_x][start_y] != 0) {
            // if (v[start_x][start_y] == v[start_x][stop_y]) return v[start_x][start_y];
            // if (v[start_x][start_y] == v[stop_x][start_y]) return v[start_x][start_y];
            // if (v[start_x][stop_y] == v[stop_x][start_y]) return v[start_x][stop_y];
            return(checkPQR(v[start_x][start_y], v[start_x][stop_y], v[stop_x][start_y]));
        }
        return 0;
    }
    int m_x = (start_x + stop_x)/2;
    int m_y = (start_y + stop_y)/2;
    int P = check_triforce(v, start_x, m_x, start_y, m_y);
    int Q = check_triforce(v, start_x, m_x, m_y+1, stop_y);
    int R = check_triforce(v, m_x+1, stop_x, start_y, m_y);
    bool is_S_zero = checkSZero(v, m_x+1, stop_x, m_y+1, stop_y);
    int is_PQR = checkPQR(P, Q, R);
    if (!is_S_zero) return 0;
    if (is_PQR == 0) return 0;
    return is_PQR;
}

int main() {
    vector<int> tmp(3);
    for (int i = 0; i < 3; i++) {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int x;
                cin >> x;
                v[j][k] = x;
            }
        }
        // check เงื่อนไข2ก่อน 
        // check ก่อนว่า S 0 หมดไหม
        // check is P, Q, R triforce
        // แบ่ง check ต่อ เป็น4ส่วน
        int ans = check_triforce(v, 0, n-1, 0, n-1);
        // cout << ans << endl;
        tmp[i] = ans;
    }
    for (auto &x : tmp) {
        cout << x << endl;
    }
}