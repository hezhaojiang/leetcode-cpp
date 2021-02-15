/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
private:
    bool transable(vector<string>& wordList, int i, int j) {
        int res = 0;
        for (int n = 0; n < wordList[i].size(); n++) {
            if (wordList[i][n] != wordList[j][n]) res++;
        }
        return res == 1;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> word2index;
        int N = wordList.size();
        for (int i = 0; i < N; i++) word2index[wordList[i]] = i;
        if (!word2index.count(endWord)) return {};
        if (!word2index.count(beginWord)) {
            wordList.push_back(beginWord);
            word2index[beginWord] = N;
        }
        N = wordList.size();

        // 预处理 建图
        vector<vector<int>> graph(N, vector<int>{});
        for (int i = 0; i < N; i++) for (int j = 0; j < i; j++) {
            if (transable(wordList, i, j)) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }

        // 广度优先搜索
        bool bcontinue = true;
        queue<vector<int>> Q;
        vector<int> visited(N, 0);
        vector<int> cost(N, INT_MAX); // 这个 cost 记录 beginword 到所有点的最短距离
        const int dest = word2index[endWord];
        vector<vector<string>> res;
        Q.push(vector<int>{word2index[beginWord]});
        visited[word2index[beginWord]] = 1;
        cost[word2index[beginWord]] = 0;

        while (!Q.empty() && bcontinue) {
            vector<int> curvisit;
            int currSize = Q.size();
            for (int i = 0; i < currSize; i++) {
                vector<int> now = Q.front();
                Q.pop();
                int index = now.back();
                if (dest == index) {
                    vector<string> tmp;
                    for (int index : now) tmp.push_back(wordList[index]);
                    res.push_back(tmp);
                    bcontinue = false;
                } else {
                    for (int j = 0; j < graph[index].size(); j++) {
                        if (visited[graph[index][j]] == 0) {
                            vector<int> copy(now);
                            copy.push_back(graph[index][j]);
                            Q.push(copy);
                            curvisit.push_back(graph[index][j]);
                        }
                    }
                }
            }
            for (auto & v : curvisit) visited[v] = 1;
        }
        return res;
    }
};
// @lc code=end

