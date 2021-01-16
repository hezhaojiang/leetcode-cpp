/*
 * @lc app=leetcode.cn id=803 lang=cpp
 *
 * [803] 打砖块
 */
#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start
vector<vector<int>> directions{{0,1},{1,0},{0,-1},{-1,0}};
#define INDEX(i,j) (cols*(i)+(j))
#define INAREA(i,j) ((i)>=0&&(i)<rows&&(j)>=0&&(j)<cols)
class UnionFind {
private:
    vector<int> parents;
    vector<int> rank; // 根节点的子节点数量 
public:
    UnionFind(int num) {
        parents.resize(num + 1);
        rank.resize(num + 1);
        for (int i = 0; i <= num; i++) {
            parents[i] = i;
            rank[i] = 1;
        }
    }
    int Find(int a) { return a == parents[a] ? a : parents[a] = Find(parents[a]); }
    void Union(int a, int b) {
        int fa = Find(a);
        int fb = Find(b);
        if (fa != fb) {
            parents[fa] = fb;
            rank[fb] += rank[fa];
        }
    }
    int Count(int a) { return rank[Find(a)]; }
};
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        // 复制 grid 数组，以区分打碎砖块的位置之前是否有砖块
        vector<vector<int>> copy(grid);
        // 将所有打碎的砖块清 0
        for (auto & hit : hits) copy[hit[0]][hit[1]] = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int size = rows * cols;
        // 创建并查集
        UnionFind uf(size);
        // 处理屋顶的砖块，将屋顶的砖块与 "屋顶" 相连，假设屋顶的 INDEX = size
        for (int j = 0; j < cols; j++) if (copy[0][j] == 1) uf.Union(j, size);
        // 连接所有未被打碎的砖块
        for (int i = 1; i < rows; i++) for (int j = 0; j < cols; j++) {
            if (copy[i][j] == 0) continue; 
            if (copy[i - 1][j] == 1) uf.Union(INDEX(i - 1, j), INDEX(i, j));
            if (j > 0 && copy[i][j - 1] == 1) uf.Union(INDEX(i, j - 1), INDEX(i, j));
        }
        
        int N = hits.size();
        vector<int> res(N, 0);
        // 逆序添加打碎砖块到并查集中
        for (int i = N - 1; i >= 0; i--) {
            int x = hits[i][0];
            int y = hits[i][1];
            // 如果该位置原本没有砖块，则跳过
            if (grid[x][y] == 0) continue;

            int origin = uf.Count(size);
            // 补回砖块
            if (x == 0) uf.Union(y, size);
            for (auto & direction : directions) {
                int nx = direction[0] + x;
                int ny = direction[1] + y;
                if (INAREA(nx, ny) && copy[nx][ny] == 1) 
                    uf.Union(INDEX(nx, ny), INDEX(x, y));
            }
            copy[x][y] = 1;
            int current = uf.Count(size);
            res[i] = max(0, current - origin - 1);
        }
        return res;
    }
};
// @lc code=end


/* Test Main */
int main(void)
{
    Solution solve;
    vector<vector<int>> grid{{1,1,1},{0,1,0},{0,0,0}};
    vector<vector<int>> hits{{0,2},{2,0},{0,1},{1,2}};
    solve.hitBricks(grid, hits);
    return 0;
}
