/*
Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Example:
Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
Follow up:
Could you do better than O(n2) per move() operation? 
*/
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        size = n;
        // H = new int *[n];
        // for(int i = 0; i < n; ++i) H[i] = new int [n];
        // for (int i = 0; i < n; ++i) 
        //     for (int j = 0; j <n ; ++j)
        //         H[i][j] = 0;
        row1.resize(n);
        row2.resize(n);
        col1.resize(n);
        col2.resize(n);
        ltrb1 = 0;
        ltrb2 = 0;
        rtlb1 = 0;
        rtlb2 = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (player == 1) {
            row1[row]++;
            col1[col]++;
            if (row == col) ltrb1++;
            if (row + col == size - 1)  rtlb1++;
            if (row1[row] == size || col1[col] == size || ltrb1 == size || rtlb1 == size) return player;
        } else {
            row2[row]++;
            col2[col]++;
            if (row == col) ltrb2++;
            if (row + col == size - 1)  rtlb2++;
            if (row2[row] == size || col2[col] == size || ltrb2 == size || rtlb2 == size) return player;
        }
        return 0;
    }

private:
    vector<int>row1,row2,col1,col2;
    int ltrb1,ltrb2,rtlb1,rtlb2;
    // int **H;
    int size;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */