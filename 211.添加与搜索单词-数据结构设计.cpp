/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */
#include <string>
using namespace std;
// @lc code=start
class WordDictionary {
private:
    bool isWord = false;
    WordDictionary* next[26] = {nullptr};

public:
    /** Initialize your data structure here. */
    WordDictionary() {}

    void addWord(string word) {
        WordDictionary* root = this;
        for (auto c : word) {
            if (root->next[c - 'a'] == nullptr)
                root->next[c - 'a'] = new WordDictionary();
            root = root->next[c - 'a'];
        }
        root->isWord = true;
    }

    bool search(string word, int pos = 0, WordDictionary* node = nullptr) {
        if (!node) node = this;
        if (pos == word.length()) return node->isWord;
        if (word[pos] != '.') {
            if (node->next[word[pos] - 'a'])
                return search(word, pos + 1, node->next[word[pos] - 'a']);
            else
                return false;
        }
        for (int i = 0; i < 26; i++) {
            if (node->next[i] != nullptr && search(word, pos + 1, node->next[i]))
                return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
