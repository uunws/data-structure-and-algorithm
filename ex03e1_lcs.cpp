#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;
    vector<vector<int>> arr(s2.length()+1, vector<int>(s1.length()+1, 0));
    int row = s2.length();
    int col = s1.length();
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            if (s2.substr(i-1, 1) == s1.substr(j-1, 1)) { // if (v2[i-1] == v1[j-1]) {
                arr[i][j] = arr[i-1][j-1] + 1;
            } else {
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }
    // // debug
    // for (int i = 0; i <= row; i++) {
    //     for (int j = 0; j <= col; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // //
    cout << arr[row][col];
}