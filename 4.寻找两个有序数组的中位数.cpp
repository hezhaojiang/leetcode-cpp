/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    double findmid(vector<int>& nums1, int n1left, int n1right,
        vector<int>& nums2, int n2left, int n2right,
        int pos)
    {
        int len1 = n1right - n1left + 1;
        int len2 = n2right - n2left + 1;

        if(len1 > len2) return findmid(nums2, n2left, n2right, 
            nums1, n1left, n1right, pos);
        if(len1 == 0) return nums2[n2left + pos - 1];

        if(pos == 1) return min(nums1[n1left], nums2[n2left]);

        int i = n1left + min(len1, pos / 2) - 1;
        int j = n2left + min(len2, pos / 2) - 1;

        if (nums1[i] > nums2[j]) 
            return findmid(nums1, n1left, n1right,
                nums2, j + 1, n2right,
                pos - (j - n2left + 1));
        else
            return findmid(nums1, i + 1, n1right, 
                nums2, n2left, n2right, 
                pos - (i - n1left + 1));
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        int leftpos = (len1 + len2) / 2;
        int rightpos = leftpos + 1;

        int rightvalue = findmid(nums1, 0, len1 - 1, nums2, 0, len2 - 1, rightpos);
        if((len1 + len2) % 2 != 0) return rightvalue;

        int leftvalue = findmid(nums1, 0, len1 - 1, nums2, 0, len2 - 1, leftpos);
        return (leftvalue + rightvalue) * 0.5;
    }
};
// @lc code=end

