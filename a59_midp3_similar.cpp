#include <iostream>

using namespace std;

bool check(string s1, string s2) {
    if (s1 == s2) return true;
    if (s1.size() > 1 && s2.size() > 1) {
        int mid = s1.size()/2;
        string s1_first = s1.substr(0, mid);
        string s1_second = s1.substr(mid);
        string s2_first = s2.substr(0, mid);
        string s2_second = s2.substr(mid);
        return (check(s1_first, s2_first) && check(s1_second, s2_second)) || (check(s1_first, s2_second) && check(s1_second, s2_first));
    } 
    return false;
}

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;
    if (check(s1, s2)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}  