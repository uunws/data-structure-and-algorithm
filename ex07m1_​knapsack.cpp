#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double W;
int N;
// vector<double> tail;
// vector<double> v; // price
// vector<double> w;
double v[100];
double w[100];
double tail[100];
double res;

void knapsack(int step, double sumP, double sumW) {
    if (sumW > W) return;
    if (tail[step] + sumP < res) return;
    if (step < N) {
        knapsack(step+1, sumP+v[step], sumW + w[step]); // select
        knapsack(step+1, sumP, sumW);
    } else { // check is it curr best
        if (sumP > res && sumW <= W) res = sumP;
    }
}


int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    cin >> W >> N;
    // v.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    // w.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }
    // backtracking : sumW > W -> return
    // B&B : tail[step] + sumP < curr_best -> return
    // tail.assign(N, 0);
    tail[N-1] = v[N-1];
    for (int i = N-2; i >= 0; i--) {
        tail[i] = tail[i+1] + v[i];
    }
    res = 0.0;
    knapsack(0,0,0);
    cout << fixed << setprecision(4) << res;
}