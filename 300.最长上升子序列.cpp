/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
//define Solution1
#define Solution2
#ifdef Solution1
        if(nums.empty()) return 0;
        vector<int> length;
        length.resize(nums.size());
        for(int i = 0; i < nums.size(); i++){
            int maxlength = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i] && maxlength < length[j])
                    maxlength = length[j];
            }
            length[i] = maxlength + 1;
        }
        int maxlength = 0;
        for(auto a : length)
            if(a > maxlength) maxlength = a;
        return maxlength;
#endif
#ifdef Solution2
        if (nums.empty()) return 0;
        vector<int> maxValue;
        for(auto n : nums){
            if (maxValue.empty() || maxValue.back() < n) maxValue.push_back(n);
            else {
                int start = 0;
                int end = maxValue.size() - 1;
                int mid = start + (end - start) / 2;
                while (start + 1 < end){
                    if (maxValue[mid] == n) break;
                    else if (maxValue[mid] < n) start = mid;
                    else end = mid;
                    mid = start + (end - start) / 2;
                }
                if (start + 1 >= end) {
                    if (maxValue[start] >= n) maxValue[start] = n;
                    else if (maxValue[end] > n) maxValue[end] = n;
                }
            }
        }
        return maxValue.size();
#endif
    }
};
// @lc code=end
int main()
{
    Solution solve;
    int result = 0;
    result = solve.lengthOfLIS(vector<int> {3,5,6,2,5,4,19,5,6,7,12});
    cout << "result:" << result << endl;
    return 0;
}
