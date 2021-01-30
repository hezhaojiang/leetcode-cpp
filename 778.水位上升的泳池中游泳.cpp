/*
 * @lc app=leetcode.cn id=778 lang=cpp
 *
 * [778] 水位上升的泳池中游泳
 */
#include<vector>
#include<queue>
using namespace std;
// @lc code=start
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int Find(int n) {
        return n == parent[n] ? n : parent[n] = Find(parent[n]);
    }
    void Union(int a, int b) {
        int rootA = Find(a), rootB = Find(b);
        if (rootA != rootB) {
            if (rank[rootA] > rank[rootB]) swap(rootA, rootB);
            parent[rootA] = rootB;
            if (rank[rootA] == rank[rootB]) rank[rootB]++;
        }
    }
};

class Solution {
private:
    struct Node {
        int x, y, h;
        Node(int _x, int _y, int _h) : x(_x), y(_y), h(_h) {};
        bool operator < (const Node& other) const {
            return this->h > other.h;
        }
    };
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        UnionFind uf(N * N);
        priority_queue<Node> nodes;
        for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
            nodes.push(Node(i, j, grid[i][j]));
        }

        while (!nodes.empty()) {
            auto& node = nodes.top();
            int z = node.x * N + node.y;
            for (int i = 0; i < 4; ++i) {
                int nx = node.x + dirs[i][0];
                int ny = node.y + dirs[i][1];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N 
                    && grid[nx][ny] <= grid[node.x][node.y]) uf.Union(nx * N + ny, z);
            }
            if (uf.Find(0) == uf.Find(N * N - 1)) return grid[node.x][node.y];
            nodes.pop();
        }
        return N * N - 1;
    }
};
// @lc code=end
