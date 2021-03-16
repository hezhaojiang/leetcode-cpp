/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */
#include <vector>
using namespace std;
// @lc code=start
class NumArray {
    int n;
    const int mod = 100;
    vector<int> sum;
    vector<int> nums;

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        sum.resize(n / mod + 1, 0);
        for (int i = 0; i < n; i++) sum[i / mod] += nums[i];
    }

    void update(int index, int val) {
        sum[index / mod] += val - nums[index];
        nums[index] = val;
    }

    int sumRange(int left, int right) {
        int lindex = left / mod;
        int rindex = right / mod;
        int res = 0;
        for (int i = lindex * mod; i < left; i++) res -= nums[i];
        for (int i = right + 1; i < min(rindex * mod + mod, n); i++) res -= nums[i];
        for (int i = lindex; i <= rindex; i++) res += sum[i];
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
