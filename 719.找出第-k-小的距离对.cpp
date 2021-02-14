/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 k 小的距离对
 */
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
private:
    bool check(vector<int>& nums, int k, int x) {
        int res = 0;
        int l = 0, r = 0, N = nums.size();
        while (r < N) {
            while (nums[r] - nums[l] > x) l++;
            res += r++ - l; // res 是距离对小于等于 x 的对数
        }
        return res >= k;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = nums[N - 1] - nums[0];
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(check(nums, k, mid)) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};
// @lc code=end

