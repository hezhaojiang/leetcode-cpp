/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int N = nums.size();
        stack<int> st, rst;
        int l = N, r = 0;
        for (int i = 0; i < N; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                l = min(l, st.top());
                st.pop();
            }
            st.push(i);
        }
        for (int i = N - 1; i >= 0; i--) {
            while (!rst.empty() && nums[rst.top()] < nums[i]) {
                r = max(r, rst.top());
                rst.pop();
            }
            rst.push(i);
        }
        return r - l > 0 ? r - l + 1 : 0;
    }
};
// @lc code=end
