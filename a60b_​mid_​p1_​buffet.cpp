#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int f,w,n;
    cin >> f >> w >> n;
    vector<int> res(f);
    for (int i = 0; i < f; i++) {
        cin >> res[i];
        res[i]--;
    }
    sort(res.begin(), res.end());
    // there are 10 block : res[i] is the index in 10 block
    // only have food 5 block : res only has 5 box
    int last = res[res.size()-1]; // index in 10 block
    int idx = res[0] + 2*w; // index in 10 block (endpoint)
    // idx : stop ตัวแรก
    int cnt = 1; // begin with 1 because we already consider first round
    while (idx <= last) { // stop <= last (if stop is more than last, mean already cover every node)
        auto it = upper_bound(res.begin(), res.end(), idx); // find next value in res after stop
        if (it == res.end()) break;  
        int after_idx = *it; // after_idx is start of the next pos
        // cout << idx << " " << after_idx << " ";
        idx = after_idx + 2*w; // this idx is the stop of the next pos
        cnt++;
        // หาตัวที่เป็นตำแหน่งที่มีอาหารที่มากกว่า idx(end) 
    }
    cout << cnt;
}
