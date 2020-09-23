/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> MAP_Words;
        queue<string> Q;
        int visit = wordList.size();
        int step = 1;

        for (int i = 0; i < wordList.size(); i++) MAP_Words[wordList[i]] = i;
        /* 哈希表 MAP_Words 有三个作用 :
         * 1. 快速判断字符串是否在 wordList 中
         * 2. 判断该字符串是否已被广度优先搜索遍历过 (MAP_Words[string] == visit)
         * 3. 判断该字符串是否是 endWord (MAP_Words[string] == -1) */
        if (MAP_Words.find(endWord) == MAP_Words.end()) return 0;
        else MAP_Words[endWord] = -1;

        /* BFS 广度优先搜索 */
        Q.push(beginWord);
        while (!Q.empty()) {
            int currSize = Q.size();
            for (int i = 0; i < currSize; i++) {
                string Word = Q.front();
                Q.pop();
                for (int i = 0; i < Word.length(); i++) {
                    string W = Word;
                    unsigned char Wordch = W[i];
                    for (unsigned char c = 'a'; c <= 'z'; c++) {
                        if (Wordch == c) continue;
                        W[i] = c;
                        if (MAP_Words.find(W) != MAP_Words.end()) {
                            if (MAP_Words[W] == -1) return step + 1;
                            else if (MAP_Words[W] == visit) continue;
                            else {
                                Q.push(W);
                                MAP_Words[W] = visit;
                            }
                        }
                    }
                }
            }
            step++;
        }
        return 0;
    }
};
// @lc code=end

