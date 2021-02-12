/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */
#include<vector>
#include<deque>
using namespace std;
// @lc code=start
class Solution {
private:
    int M, N;
    const vector<vector<int>> dis{{1,0},{-1,0},{0,1},{0,-1}};
    bool isvalid(int i, int j) {
        return i >= 0 && j >= 0 && i < M && j < N;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int preColor = image[sr][sc];
        if (preColor == newColor) return image;
        M = image.size();
        N = image[0].size();
        deque<pair<int, int>> q;
        q.emplace_back(sr, sc);
        image[sr][sc] = newColor;
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop_front();
            for (auto & d : dis) {
                int x = i + d[0], y = j + d[1];
                if (isvalid(x, y) && image[x][y] == preColor) {
                    q.emplace_back(x, y);
                    image[x][y] = newColor;
                }
            }
        }
        return image;
    }
};
// @lc code=end

