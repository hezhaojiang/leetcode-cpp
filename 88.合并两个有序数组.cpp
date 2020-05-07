/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m - 1, j = n - 1; j >= 0;)
        {
            if(i < 0 || nums1[i] < nums2[j]) {nums1[i + j + 1] = nums2[j];j--;}
            else {nums1[i + j + 1] = nums1[i];i--;}
        }
        return;
    }
};
// @lc code=end

