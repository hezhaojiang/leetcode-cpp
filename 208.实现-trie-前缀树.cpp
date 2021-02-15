/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include <string>
using namespace std;
// @lc code=start
class Trie {
private:
    bool isWord = false;
    Trie* next[26] = {nullptr};

public:
    /** Initialize your data structure here. */
    Trie() {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for (auto c : word) {
            if (root->next[c - 'a'] == nullptr) root->next[c - 'a'] = new Trie;
            root = root->next[c - 'a'];
        }
        root->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        for (auto c : word) {
            if (root->next[c - 'a'] == nullptr) return false;
            root = root->next[c - 'a'];
        }
        return root->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        for (auto c : prefix) {
            if (root->next[c - 'a'] == nullptr) return false;
            root = root->next[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
