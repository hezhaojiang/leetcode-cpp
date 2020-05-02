/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        for(; left != right;)
        {
            if(numbers[left] + numbers[right] == target)
                break;
            if(numbers[left] + numbers[right] > target)
                right--;
            else
                left++;
        }
        return vector<int>{left + 1, right + 1};
    }
};
// @lc code=end

