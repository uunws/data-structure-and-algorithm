#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    vector<int> v(n-1);
    for (int i = 0; i < n-1; i++) {
        v[i] = max(A[i], A[i+1]);
    }
    
    for (int i = n-4; i >= 0; i-=2) { // จำนวนสมาชิกในแนวเส้นทแยงมุม
        vector<int> new_v(i+1, 0);
        for (int j = 0; j <= i; j++) { // ไล่ row
            int col = j + (n-i-1); // สมมติ (0, 3) j = 0(rowที่0) + (6-2-1) 
            if (col >= n)  continue; // ถ้า col มากกว่า n ข้ามไปเลย
            new_v[j] = max({v[j] + max(A[col], A[col-1]), v[j+1] + max(A[j], A[col]), v[j+2] + max(A[j], A[j+1])});
            
        }
        v = new_v;
        
    }
    cout << v[0];
}