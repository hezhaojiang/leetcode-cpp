/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    void dfs(vector<vector<char>>& board, int row, int col) {
        int BOOOOOOOOOOOOOOMNum = 0;
        int x[8] = {1, 1, 0, -1, -1, -1,  0,  1};
        int y[8] = {0, 1, 1,  1,  0, -1, -1, -1};
        if (board[row][col] == 'E') {
            for(int i = 0; i < 8; i++) {
                if (row + x[i] >= 0 && row + x[i] < board.size()
                    && col + y[i] >= 0 && col + y[i] < board[0].size()
                    && board[row + x[i]][col + y[i]] == 'M')
                    BOOOOOOOOOOOOOOMNum++;
            }
        }
        if (BOOOOOOOOOOOOOOMNum == 0) board[row][col] = 'B';
        else { 
            board[row][col] = '0' + BOOOOOOOOOOOOOOMNum;
            return;
        }

        for(int i = 0; i < 8; i++) {
            if (row + x[i] >= 0 && row + x[i] < board.size()
                && col + y[i] >= 0 && col + y[i] < board[0].size()
                && board[row + x[i]][col + y[i]] == 'E')
                dfs(board, row + x[i], col + y[i]);
        }
        return;
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        dfs(board, click[0], click[1]);
        return board;
    }
};
// @lc code=end

