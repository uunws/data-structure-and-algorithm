#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string x, y;
    cin >> x;
    cin >> y;
    vector<vector<int>> L(n+1, vector<int> (m+1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> L[i][j];
        }
    }
    int row = n;
    int col = m;
    string s = "";
    while (row > 0 && col > 0) {
        if (L[row][col] == L[row-1][col-1] + 1) {
            s = s + y[col-1];
            row--;
            col--;
        } else {
            if (L[row][col] == L[row][col-1]) {
                col--;
            } else {
                row--;
            }
        }
    }
    cout << s;
}