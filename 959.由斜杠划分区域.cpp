/*
 * @lc app=leetcode.cn id=959 lang=cpp
 *
 * [959] 由斜杠划分区域
 */
#include<vector>
#include<string>
using namespace std;
/* 
 * 单元格内：
 * +------+
 * |\  0 /|
 * | \  / |
 * |3 \/ 1| 
 * |  /\  |
 * | /  \ |
 * |/  2 \|
 * +------+
 * 如果是空格：合并 0、1、2、3；
 * 如果是斜杠：合并 0、3，合并 1、2；
 * 如果是反斜杠：合并 0、1，合并 2、3。
 */
// @lc code=start
class UnionFind {
private:
    vector<int> parent;
    int count;
public:
    UnionFind(int n) {
        count = n;
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int Find(int n) {
        return n == parent[n] ? n : parent[n] = Find(parent[n]);
    }
    void Union(int a, int b) {
        int rootA = Find(a), rootB = Find(b);
        if (rootA != rootB) {
            count--;
            parent[rootA] = rootB;
        }
    }
    int Count() { return count; }
};
/* 
 * 单元格内：
 * +------+
 * |\  0 /|
 * | \  / |
 * |3 \/ 1| 
 * |  /\  |
 * | /  \ |
 * |/  2 \|
 * +------+
 * 如果是空格：合并 0、1、2、3；
 * 如果是斜杠：合并 0、3，合并 1、2；
 * 如果是反斜杠：合并 0、1，合并 2、3。
 */
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int M = grid.size();
        int N = 4 * M * M;
        UnionFind uf(N);
#       define INDEX(i,j) (4*((i)*M+(j)))
        for (int i = 0; i < M; i++) for (int j = 0; j < M; j++) {
            int index = INDEX(i,j);
            // 单元格内合并
            if (grid[i][j] == '\\') {
                uf.Union(index + 0, index + 1);
                uf.Union(index + 2, index + 3);
            } else if (grid[i][j] == '/') {
                uf.Union(index + 0, index + 3);
                uf.Union(index + 2, index + 1);
            } else {
                uf.Union(index + 0, index + 1);
                uf.Union(index + 2, index + 3);
                uf.Union(index + 2, index + 1);
            }
            // 单元格间合并
            if (i != M - 1) {// 向下合并
                uf.Union(index + 2, INDEX(i+1,j));
            }
            if (j != M - 1) {// 向右合并
                uf.Union(index + 1, INDEX(i,j+1) + 3);
            }
        }
        return uf.Count();
    }
};
// @lc code=end

