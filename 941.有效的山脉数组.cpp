/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int N = A.size();
        if (N < 3) return false;
        int left = 0, right = N - 1;
        while(left < N - 1 && A[left] < A[left + 1]) left++;
        while(right > 0 && A[right - 1] > A[right]) right--;
        if (left != 0 && right != N - 1 && left == right) return true;
        return false;
    }
};
// @lc code=end

