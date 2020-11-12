/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int N = A.size();
        int i = 0, j = 1;
        while (i < N && j < N) {
            if (A[i] % 2 != 0 && A[j] % 2 == 0) swap(A[i], A[j]);
            if (A[i] % 2 == 0) i = i + 2;
            if (A[j] % 2 != 0) j = j + 2;
        }
        return A;
    }
};
// @lc code=end

