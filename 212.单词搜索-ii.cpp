/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Trie {
public:
    string word = "";
    Trie* next[26] = {nullptr};
    void insert(string word) {
        Trie* root = this;
        for (auto c : word) {
            if (root->next[c - 'a'] == nullptr) root->next[c - 'a'] = new Trie;
            root = root->next[c - 'a'];
        }
        root->word = word;
    }
};
class Solution {
private:
    vector<string> res;
    void dfs(vector<vector<char>>& board, Trie* node, int x, int y) {
        char c = board[x][y];
        if (c == '.' || node->next[c - 'a'] == nullptr) return;
        node = node->next[c - 'a'];
        if (!node->word.empty()) {
            res.push_back(node->word);
            node->word = "";
        }
        board[x][y] = '.';
        if (x > 0) dfs(board, node, x - 1, y);
        if (y > 0) dfs(board, node, x, y - 1);
        if (x < board.size() - 1) dfs(board, node, x + 1, y);
        if (y < board[0].size() - 1) dfs(board, node, x, y + 1);
        board[x][y] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trieDirc;
        for (auto& s : words) trieDirc.insert(s);
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, &trieDirc, i, j);
            }
        return res;
    }
};
// @lc code=end

