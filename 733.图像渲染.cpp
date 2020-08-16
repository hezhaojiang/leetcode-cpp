/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
#define MAX_COLOR 65535
    int color;
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == color) image[sr][sc] += MAX_COLOR;
        if (sr > 0 && image[sr - 1][sc] == color) dfs(image, sr - 1, sc, newColor);
        if (sr < image.size() - 1 && image[sr + 1][sc] == color) dfs(image, sr + 1, sc, newColor);
        if (sc > 0 && image[sr][sc - 1] == color) dfs(image, sr, sc - 1, newColor);
        if (sc < image[0].size() - 1 && image[sr][sc + 1] == color) dfs(image, sr, sc + 1, newColor);
        image[sr][sc] = newColor;
        return;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        color = image[sr][sc];
        dfs(image, sr, sc, newColor);
        return image;
    }
};
// @lc code=end

