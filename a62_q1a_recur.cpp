#include <iostream>
#include <vector>
using namespace std;

void recur(vector<vector<int>> &v, int a, int b, int top, int bottom, int left, int right) {
    if (a == 0) {
        v[top][left] = b;
        return;
    }
    int mid_top_bottom = (top+bottom)/2;
    int mid_left_right = (left+right)/2;
    recur(v, a-1, b, top, mid_top_bottom, left, mid_left_right);
    recur(v, a-1, b-1, top, mid_top_bottom, mid_left_right+1, right);
    recur(v, a-1, b+1, mid_top_bottom+1, bottom, left, mid_left_right);
    recur(v, a-1, b, mid_top_bottom+1, bottom, mid_left_right+1, right);   
}

int main() {
    int a, b;
    cin >> a >> b;
    int p = 1<<a;
    vector<vector<int>> v(p , vector<int>(p, 0));
    recur(v, a, b, 0, p - 1, 0, p - 1);
    for (auto & x: v) {
        for (auto & y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}