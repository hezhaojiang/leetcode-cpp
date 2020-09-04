/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<string>> result;
    void dfs(vector<string> & chess, int line) {
        for (int i = 0; i < chess[line].length(); i++) {
            if (chess[line][i] == '0') {
                vector<string> chesscp = chess;
                for (int j = 0; j < chesscp[line].length(); j++) chesscp[line][j] = '.';
                for (int j = 0; j < chesscp.size(); j++) chesscp[j][i] = '.';
                for (int j = 0; j < chesscp.size(); j++) {
                    int k = line + i - j;
                    if (0 <= k && k < chesscp.size()) chesscp[j][k] = '.';
                }
                for (int j = 0; j < chesscp.size(); j++) {
                    int k = j - (line - i);
                    if (0 <= k && k < chesscp.size()) chesscp[j][k] = '.';
                }
                chesscp[line][i] = 'Q';
                if (line == chess.size() - 1) result.push_back(chesscp);
                else dfs(chesscp, line + 1);
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chess(n, string(n, '0'));
        dfs(chess, 0);
        return result;
    }
};
// @lc code=end

