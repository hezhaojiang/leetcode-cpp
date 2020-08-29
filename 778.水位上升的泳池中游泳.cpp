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
    std::vector<int> parent;
    std::vector<int> rank;
public:
    UnionFind(int size) : parent(std::vector<int>(size)) ,rank(std::vector<int>(size)) {
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    /* 对 MakeSet 函数进行按秩合并优化 */
    void MakeSet(int x) {
        if (x < parent.size()) parent[x] = x;
        else {
            int osize = parent.size();
            parent.resize(x + 1);
            rank.resize(x + 1);
            for (int i = osize; i <= x; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }
    }
    /* 对 Find 函数进行路径压缩优化 */
    int Find(int x) {
        if (parent[x] != x) parent[x] = Find(parent[x]);
        return parent[x];
    }
    /* 对 Union 函数进行按秩合并优化 */
    void Union(int x, int y) {
        int xRoot = Find(x);
        int yRoot = Find(y);
        if (xRoot == yRoot) return;
        if (rank[xRoot] < rank[yRoot]) parent[xRoot] = yRoot;
        else if (rank[xRoot] > rank[yRoot]) parent[yRoot] = xRoot;
        else {parent[yRoot] = xRoot; rank[xRoot]++; }
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
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                nodes.push(Node(i, j, grid[i][j]));
            }
        }
        for (int t = 0; t < N * N; ++t) {
            while (!nodes.empty() && nodes.top().h == t) {
                auto node = nodes.top();
                nodes.pop();
                int z = node.x * N + node.y;
                for (int i = 0; i < 4; ++i) {
                    int nx = node.x + dirs[i][0];
                    int ny = node.y + dirs[i][1];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < N && grid[nx][ny] <= t) {
                        int nz = nx * N + ny;
                        uf.Union(nz, z);
                    }
                }
            }
            if (uf.Find(0) == uf.Find(N * N - 1)) return t;
        }
        return N * N - 1;
    }
};
// @lc code=end
