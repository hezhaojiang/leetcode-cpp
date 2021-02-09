/*
 * @lc app=leetcode.cn id=992 lang=cpp
 *
 * [992] K 个不同整数的子数组
 */
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int N = A.size();
        int numcal = 0;
        unordered_map<int, int> num2count;
        int res = 0;
        int left = 0, right = 0;
        while (right < N) {
            int rvalue = A[right++];
            if (num2count.count(rvalue) && num2count[rvalue] != 0) {
                num2count[rvalue]++;
            } else {
                num2count[rvalue] = 1;
                numcal++;
            }

            // 右端点不符合要求了，需要向右移动左端点
            while (numcal > K) {
                int lvalue = A[left++];
                if (--num2count[lvalue] == 0) numcal--;
            }

            // 找到符合要求的右端点，计算左端点数量
            unordered_map<int, int> left2count;
            int leftend = left;
            while (numcal == K) {
                if (++left2count[A[leftend]] == num2count[A[leftend]]) {
                    res += leftend - left + 1;
                    cout << leftend - left + 1 << endl;
                    break;
                }
                leftend++;
            }
        }
        return res;
    }
};
// @lc code=end

int main()
{
    Solution solve;
    vector<int> A{2,1,1,1,2};
    int res = solve.subarraysWithKDistinct(A, 1);
    cout << res << endl;
    return 0;
}

