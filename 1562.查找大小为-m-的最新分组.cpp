/*
 * @lc app=leetcode.cn id=1562 lang=cpp
 *
 * [1562] 查找大小为 M 的最新分组
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        vector<int> findPoint(arr.size());
        vector<int> markPoint(arr.size(), 0);
        int count = 0;
        int step = -1;
        for (int i = 0; i < arr.size(); i++) {
            int index = arr[i] - 1;
            markPoint[index] = 1;
            bool connectleft = ((index != 0) && (markPoint[index - 1] == 1));
            bool connectright = ((index != arr.size() - 1) && (markPoint[index + 1] == 1));
            /* case left = 0 && right = 0 */
            if (!connectleft && !connectright) {
                findPoint[index] = index;
                if (1 == m) count++;
            }
            /* case left = 1 && right = 1 */
            else if (connectleft && connectright) {
                
                if (index - findPoint[index - 1] == m) count--;
                if (findPoint[index + 1] - index == m) count--;
                if (findPoint[index + 1] - findPoint[index - 1] + 1 == m) count++;
                int left = findPoint[index - 1];
                findPoint[findPoint[index - 1]] = findPoint[index + 1];
                findPoint[findPoint[index + 1]] = left;
            }
            /* case left = 0 && right = 1 */
            else if (!connectleft && connectright) {
                if (findPoint[index + 1] - index == m) count--;
                if (findPoint[index + 1] - index + 1 == m) count++;
                int right = findPoint[index + 1];
                findPoint[findPoint[index + 1]] = index;
                findPoint[index] = right;
            }
            else {
                if (index - findPoint[index - 1] == m) count--;
                if (index - findPoint[index - 1] + 1 == m) count++;
                int left = findPoint[index - 1];
                findPoint[findPoint[index - 1]] = index;
                findPoint[index] = left;
            }
            if (count != 0) step = i + 1;
        }
        return step;
    }
};
// @lc code=end

