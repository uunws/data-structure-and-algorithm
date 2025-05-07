#include <bits/stdc++.h>

using namespace std;


// เก็บคำตอบที่เจอไปแล้ว ถ้าเจอไปแล้วไม่ต้องคิด
// ใช้ recur แบบ bfs?

int main() {
    int x;
    cin >> x;
    queue<pair<int,int>> q;
    set<int> already_ans;
    q.push({x,0}); // เก็บค่า กับ จำนวนครั้งที่ทำ operation
    while (!q.empty()) {
        pair<int,int> curr = q.front();
        int val = curr.first;
        int cnt = curr.second;
        q.pop();
        if (val == 0) {
            cout << cnt << endl;
            return 0;
        }
        // operation 1
        int x1 = (val+1)%16777216;
        if (already_ans.find(x1) == already_ans.end()) {
            q.push({x1,cnt+1});
            already_ans.insert(x1);
        }  
        // operation 2
        int x2 = (val*2)%16777216; 
        if (already_ans.find(x2) == already_ans.end()) {
            q.push({x2,cnt+1});
            already_ans.insert(x2);
        }
    }
}