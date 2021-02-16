/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Trie {
private:
    string s = "";
    Trie* next[26] = {nullptr};

public:
    void insert(string word) {
        Trie* root = this;
        for (auto c : word) {
            if (root->next[c - 'a'] == nullptr) root->next[c - 'a'] = new Trie;
            root = root->next[c - 'a'];
        }
        root->s = word;
    }
    string getPrefix(string word) {
        Trie* root = this;
        for (auto c : word) {
            if (root->next[c - 'a'] == nullptr) return word;
            root = root->next[c - 'a'];
            if (root->s != "") return root->s;
        }
        return word;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie dict;
        for (auto& s : dictionary) dict.insert(s);
        istringstream line(sentence);
        string res, word;
        while (line >> word) {
            res += dict.getPrefix(word) + " ";
        }
        if (res.size() > 0) res.resize(res.size() - 1);  //删除最后一个空格
        return res;
    }
};
// @lc code=end
