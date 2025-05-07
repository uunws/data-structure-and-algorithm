#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <cstdlib>

using namespace std;

const int SPACE = 0; // number 0 is the empty space

const vector<vector<int>> goal = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 0}  // 0 is the empty SPACE
};

const vector<vector<int>> goal_pos = {
    {3, 3},  // goal position for piece 0 (the empty SPACE) which should be at 3,3
    {0, 0},  // goal position for piece 1
    {0, 1},  // goal position for piece 2
    {0, 2},  // goal position for piece 3
    {0, 3},  // goal position for piece 4
    {1, 0},  // goal position for piece 5
    {1, 1},  // goal position for piece 6
    {1, 2},  // goal position for piece 7
    {1, 3},  // goal position for piece 8
    {2, 0},  // goal position for piece 9
    {2, 1},  // goal position for piece 10
    {2, 2},  // goal position for piece 11
    {2, 3},  // goal position for piece 12
    {3, 0},  // goal position for piece 13
    {3, 1},  // goal position for piece 14
    {3, 2}   // goal position for piece 15
};

class Board {
public:
    vector<vector<int>> b;  // the board, b[i][j] = piece at row i col j
    vector<int> move;      // list of movements we have done on this board
                           // move[0] is the first move where 0,1,2,3 is up, down, left, right
    int r, c;              // row and column of the empty space
    int heuristic_value;    // heuristic value of this board
    int heuristic_mode;     // selector for heuristic calculation

    // Constructor, initialize as goal
    Board() {
        b = goal;
        r = c = 3;
        heuristic_mode = 0;
    }

    bool is_goal() {
        return b == goal;
    }

    // Move the space in any of four directions
    // direction 0,1,2,3 = up, down, left, right
    // return true if move is successful
    bool do_move(int direction) {
        if (direction == 0) {  // up
            if (r == 0) return false;
            b[r][c] = b[r-1][c];
            b[r-1][c] = SPACE;
            r--;
        } else if (direction == 1) {  // down
            if (r == 3) return false;
            b[r][c] = b[r+1][c];
            b[r+1][c] = SPACE;
            r++;
        } else if (direction == 2) {  // left
            if (c == 0) return false;
            b[r][c] = b[r][c-1];
            b[r][c-1] = SPACE;
            c--;
        } else if (direction == 3) {  // right
            if (c == 3) return false;
            b[r][c] = b[r][c+1];
            b[r][c+1] = SPACE;
            c++;
        }
        move.push_back(direction);
        
        // Calculate the heuristic value of this board
        if (heuristic_mode == 0)
            heuristic_value = heuristic_0();  // number of displaced pieces
        else
            heuristic_value = heuristic_1();  // sum of distance of displaced pieces
        
        return true;
    }

    // Number of current move + number of displaced piece
    int heuristic_0() {
        int count = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (b[i][j] != SPACE && b[i][j] != goal[i][j]) count++;
            }
        }
        return move.size() + count;
    }

    // Number of current move + sum of Manhattan distances of displaced pieces to their positions
    int heuristic_1() {
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (b[i][j] != SPACE) {
                    int row_diff = abs(i - goal_pos[b[i][j]][0]);
                    int col_diff = abs(j - goal_pos[b[i][j]][1]);
                    sum += row_diff + col_diff;
                }
            }
        }
        return move.size() + sum;
    }

    // For std::set to check if this is the same board
    bool operator<(const Board& other) const {
        return this->b < other.b;
    }

    void print() {
        cout << "move = " << move.size() << endl;
        for (auto &x : move) { cout << x << " "; }
        cout << endl;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Heuristic_compare {
public:
    bool operator()(const Board& b1, const Board& b2) {
        return b1.heuristic_value > b2.heuristic_value;
    }
};

void bfs(Board start) {
    set<Board> boards;  // list of boards we have seen
    queue<Board> q;
    q.push(start);
    boards.insert(start);

    while (q.empty() == false) {
        Board b = q.front(); q.pop();
        b.print();
        if (b.is_goal()) {
            cout << "=== found the solution ===" << endl;
            cout << "number of move = " << b.move.size() << endl;
            cout << "we have generated a total of " << boards.size() << " states" << endl;
            for (auto &x : b.move) { cout << x << " "; } cout << endl;
            return;
        }

        // Try all four possible moves
        for (int dir = 0; dir < 4; dir++) {
            Board new_board = b;
            if (new_board.do_move(dir)) {
                if (boards.find(new_board) == boards.end()) {
                    boards.insert(new_board);
                    q.push(new_board);
                }
            }
        }
    }
    cout << "No solution found!" << endl;
}

void c_search(Board start) {
    set<Board> boards;  // list of boards we have seen
    priority_queue<Board, vector<Board>, Heuristic_compare> pq;
    pq.push(start);
    boards.insert(start);

    while (pq.empty() == false) {
        Board b = pq.top(); pq.pop();
        b.print();
        if (b.is_goal()) {
            cout << "=== found the solution ===" << endl;
            cout << "number of move = " << b.move.size() << endl;
            cout << "we have generated a total of " << boards.size() << " states" << endl;
            for (auto &x : b.move) { cout << x << " "; } cout << endl;
            return;
        }

        // Try all four possible moves
        for (int dir = 0; dir < 4; dir++) {
            Board new_board = b;
            if (new_board.do_move(dir)) {
                if (boards.find(new_board) == boards.end()) {
                    boards.insert(new_board);
                    pq.push(new_board);
                }
            }
        }
    }
    cout << "No solution found!" << endl;
}

int main() {
    Board start;
    start.do_move(0); // move up 2 times
    start.do_move(0);
    start.do_move(2); // move left
    start.move.clear(); // clear the move recording
    
    cout << "--- start ---" << endl;
    start.print();
    
    // Breadth-first search
    bfs(start);
    
    // A* search with heuristic mode = 0
    start.heuristic_mode = 0;
    c_search(start);
    
    // A* search with heuristic mode = 1
    start.heuristic_mode = 1;
    c_search(start);
    
    return 0;
}