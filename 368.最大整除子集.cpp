/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int N = nums.size();
        if (N == 0) return {};
        int maxLengh = 0; // 最长序列长度
        int maxIndex = 0; // 最长序列结尾下标
        sort(nums.begin(), nums.end());
        vector<int> maxlength(N, 1);
        vector<int> lastindex(N, -1);
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < j; i++) {
                if (nums[j] % nums[i] == 0 && maxlength[i] + 1 > maxlength[j]) {
                    maxlength[j] = maxlength[i] + 1;
                    lastindex[j] = i;
                    if (maxLengh < maxlength[j]) {
                        maxLengh = maxlength[j];
                        maxIndex = j;
                    }
                }
            }
        }
        vector<int> ret;
        while(maxIndex >= 0) {
            ret.push_back(nums[maxIndex]);
            maxIndex = lastindex[maxIndex];
        }
        return ret;
    }
};
// @lc code=end

/* Test Main */
int main(void)
{
    Solution solve;
    vector<int> arr{1,2,3};
    solve.largestDivisibleSubset(arr);
    return 0;
}
