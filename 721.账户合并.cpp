/*
 * @lc app=leetcode.cn id=721 lang=cpp
 *
 * [721] 账户合并
 */
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int Find(int n) {
        return n == parent[n] ? n : parent[n] = Find(parent[n]);
    }
    void Union(int a, int b) {
        int rootA = Find(a), rootB = Find(b);
        if (rootA != rootB) parent[rootA] = rootB;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int N = accounts.size();
        UnionFind uf(N);
        unordered_map<string, int> emailtoAccindex;
        for (int i = 0; i < N; i++) for (int j = 1; j < accounts[i].size(); j++) {
            if (emailtoAccindex.count(accounts[i][j]) == 0) emailtoAccindex[accounts[i][j]] = i;
            else uf.Union(emailtoAccindex[accounts[i][j]], i);
        }
        unordered_map<int, vector<string>> accindextoEmails;
        for (auto& [email, index] : emailtoAccindex) accindextoEmails[uf.Find(index)].push_back(email);
        vector<vector<string>> result;
        for (auto& [index, emails] : accindextoEmails) {
            sort(emails.begin(), emails.end());
            result.push_back(vector<string> {accounts[index][0]} );
            result.back().insert(result.back().end(), emails.begin(), emails.end());
        }
        return result;
    }
};
// @lc code=end

