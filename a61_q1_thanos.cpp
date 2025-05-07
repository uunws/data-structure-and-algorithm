#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

int count_avengers(unordered_map<int, int> &v, int l, int r) {
    if (l == r) {
        return v[l];
    }
    int mid = (l+r)/2;
    return count_avengers(v, l, mid) + count_avengers(v, mid+1, r);
}

long long thanos(unordered_map<int, int> &v, int start, int stop, int A, int B) {
    int curr_count = count_avengers(v, start, stop);
    if (curr_count == 0) return A;
    long long en1 = 1LL*B*curr_count*(stop-start+1);
    if (start == stop) return en1;
    int mid = (start+stop)/2;
    long long en2 = thanos(v, start, mid, A, B) + thanos(v, mid + 1, stop, A, B);
    return min(en1, en2); 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int p, k, A, B;
    cin >> p >> k >> A >> B;
    int pp = 1 << p;
    unordered_map<int, int> v;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        v[a-1]++;
    }
    cout << thanos(v, 0, pp-1, A, B) << endl;
}

