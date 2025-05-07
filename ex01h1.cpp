#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<long long> index;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        index.push(x);
    }
    int i = 0;
    while(!index.empty()) {
        auto focus = index.top();
        index.pop();
        while (i != focus) {
            
        }
        i = focus;
    }
}