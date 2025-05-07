#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<vector<int>> grid;

// move 0
// ขยับไปกลับ, ออกขอบ ไม่ได้
// find minimum

struct Compare {
    bool operator()(const pair<vector<int>, vector<vector<int>>> &a,
                    const pair<vector<int>, vector<vector<int>>> &b) const {
        return a.first[0] > b.first[0];  // this mean min->max
    }
};

vector<vector<int>> goal = 
{
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,0}
};

vector<vector<int>> moved_vec = {{-1,0},{1,0},{0,-1},{0,1}}; // U D L R  0 1 2 3
vector<int> cannot_move = {1,0,3,2};

vector<vector<int>> goal_pos = 
{
    {3,3}, // 0
    {0,0}, // 1
    {0,1}, // 2
    {0,2}, // 3
    {0,3}, // 4
    {1,0}, // 5
    {1,1}, // 6
    {1,2}, // 7
    {1,3}, // 8
    {2,0}, // 9
    {2,1}, // 10
    {2,2}, // 11
    {2,3}, // 12
    {3,0}, // 13
    {3,1}, // 14
    {3,2}, // 15

};

int find_misplaced(vector<vector<int>> &grid) {
    // int cnt = 0;
    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         if (grid[i][j] != goal[i][j]) cnt++;
    //     }
    // }
    // return cnt;
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == 0) continue;
            int dr = abs(i-goal_pos[grid[i][j]][0]);
            int dc = abs(j-goal_pos[grid[i][j]][1]);
            sum += dr + dc;
        }
    }
    return sum;
}

int main() {

    grid.assign(4, vector<int> (4, 0));
    int x,y;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 0) {
                x = i; y = j;
            }
        }
    }

    priority_queue<pair<vector<int>, vector<vector<int>>>, vector<pair<vector<int>, vector<vector<int>>>>, Compare> pq;
    int start_misplaced = find_misplaced(grid); // + 0(moved)
    pq.push({{start_misplaced, x, y, -1, 0}, grid}); // score, x of 0, y of 0, last move : 0, 1, 2, 3, moved
    set<vector<vector<int>>> s;
    s.emplace(grid); // อย่าลืมเพิ่มตารางแรกลงไปด้วย

    while (!pq.empty()) {

        auto curr = pq.top(); pq.pop();
        int x = curr.first[1];
        int y = curr.first[2];
        int last_move = curr.first[3];
        int moved = curr.first[4];

        vector<vector<int>> curr_grid = curr.second;

        for (int dir = 0; dir < 4; dir++) {
            if (dir == cannot_move[last_move] && last_move != -1) continue; // อย่าลืม check ว่าไม่ใช่ตัวแรก
            int new_x = x + moved_vec[dir][0]; // ตำแหน่งใหม่ที่ 0 ต้องไปอยู่
            int new_y = y + moved_vec[dir][1];
            if (new_x >= 0 && new_y >= 0 && new_x < 4 && new_y < 4) {
                auto new_grid = curr_grid; // อย่าลืม copy เป็น tmp ก่อน เพราะ ถ้ามันไปไม่ถึง push จะได้ roll back ได้
                swap(new_grid[x][y] ,new_grid[new_x][new_y]);
                // new_grid[new_x][new_y] = 0;

                if (s.find(new_grid) != s.end()) { // there are different move that give the same board
                    continue;
                } 

                int miss = find_misplaced(new_grid);
                if (miss == 0) {
                    cout << moved+1 << endl;
                    return 0;
                }
                int score = miss + moved + 1; // known part(moved+1) + unknown part(miss)
                s.emplace(new_grid);
                // cout << new_x << " " << new_y << endl;
                pq.push({{score, new_x, new_y, dir, moved+1},new_grid});
            }
        }

    }
}