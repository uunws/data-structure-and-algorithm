#include <iostream>
#include <vector>
using namespace std;

void combi_kn(int n, vector<int> &sol, int len, int k, int chosen) {
        // combi choose not more than k items from n items
        if (len < n) {
            sol[len] = 0;
            combi_kn(n, sol, len+1, k, chosen);
            if (chosen < k) {
                sol[len] = 1;
                combi_kn(n, sol, len+1, k, chosen+1);
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (sol[i] == 1) {
                    cout << i+1 << " ";
                }
            }
            cout << endl;
        }
    }

int main() {
    vector<int> sol(5);
    combi_kn(5, sol, 0, 3, 0);
}