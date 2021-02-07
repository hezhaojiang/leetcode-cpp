/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int N = arr.size();
        if (N < 2) return N;
        int maxlen = 0;
        int left = 0, right = 1;
        bool prestate = false; // false 下降 true 上升
        while (right < N) {
            bool state = arr[right] > arr[right - 1];
            if (prestate == state) left = right - 1;
            if (arr[right] == arr[right - 1]) left = right;
            prestate = state;
            right++;
            maxlen = max(maxlen, right - left);
        }
        return maxlen;
    }
};
// @lc code=end

