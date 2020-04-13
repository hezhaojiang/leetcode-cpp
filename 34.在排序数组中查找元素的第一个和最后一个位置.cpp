/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<int> result;
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {

        if(nums.size() == 0) 
        {
            result.push_back(-1); result.push_back(-1); return result;
        }
        int start = 0;
        int end = nums.size() - 1;
        int mid = (start + end) / 2;
        while(mid != end)
        {
            if(nums[mid] == target) break;
            if(nums[mid] > target) end = mid;
            if(nums[mid] < target) start = mid + 1;
            mid = (start + end) / 2;
        }
        if(nums[mid] != target)
        {
            result.push_back(-1); result.push_back(-1); return result;
        }

        int lstart = start;
        int lend = mid;
        int lmid = (lstart + lend) / 2;
        while(lmid != lend)
        {
            if(nums[lmid] == target) lend = lmid;
            if(nums[lmid] < target) lstart = lmid + 1;
            lmid = (lstart + lend) / 2;
        }

        int rstart = mid;
        int rend = end;
        int rmid = (rstart + rend + 1) / 2;

        while(rmid != rstart)
        {
            if(nums[rmid] > target) rend = rmid - 1;
            if(nums[rmid] == target) rstart = rmid;
            rmid = (rstart + rend + 1) / 2;
        }

        result.push_back(lmid);
        result.push_back(rmid);
        return result;
    }
};
// @lc code=end


