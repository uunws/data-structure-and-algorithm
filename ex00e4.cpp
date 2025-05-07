#include <iostream>
#include <vector>
using namespace std;

void permu(vector<string> &ans, string s, int a, int b, int c, int count_a, int count_c) {
    if (count_a < a) {
        permu(ans, s+"1", a, b, c, count_a+1, count_c);
    }
    if (count_c < c) {
        permu(ans, s+"0", a, b, c, count_a, count_c+1);
    }
    if (s.size() == b) {
        ans.push_back(s);

    }
}

int main() {
    int a, b;
    cin >> a >> b;
    vector<string> ans;
    string s;
    permu(ans, s, a, b, b-a, 0, 0);
    for (auto &x : ans) {
        cout << x << endl;
    }
}