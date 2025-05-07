// kadane's algorithm
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    int res = arr[0];
    int maxEnd = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        maxEnd = max(maxEnd+arr[i], arr[i]);
        res = max(res, maxEnd);
    }
    cout << res << endl;

// matrix chain multiplication
int main() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 0; i <= n; i++) { // n+1 : คูณmatrix 3 ตัว ต้องมีsize 4 ตัว
        cin >> v[i];
    }
    vector<vector<int>> b(n, vector<int>(n, 0)); // 0-base + trivial case ที่ b[x][x] = 0
    for (int len = 1; len < n; len++) { // ค.ยาวของเส้นทแยงมุม = n - len
        for (int i = 0; i < n-len; i++) { // 0-base (row)
            if (len == 1) { // trivial case
                b[i][i+1] = v[i]*v[i+1]*v[i+2];
            } else {
                int j = i + len;
                b[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    int op = b[i][k] + b[k+1][j] + v[i]*v[k+1]*v[j+1];
                    b[i][j] = min(b[i][j], op); // ไล่แต่ละoption แล้วเอาค่าmin
                }
            }
        }
    }
    cout << b[0][n-1];
}