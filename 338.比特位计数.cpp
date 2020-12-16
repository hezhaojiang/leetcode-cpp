/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
#if 0
    int hammingWeight(uint32_t n) {
        if (n == 0) return 0;
        return hammingWeight(n & (n - 1)) + 1;
    }
    vector<int> countBits(int num) {
        vector<int> result;
        for (int i = 0; i <= num; i++) {
            result.push_back(hammingWeight(i));
        }
        return result;
    }
#endif
    vector<int> countBits(int num) {
        vector<int> result{0};
        while (result.size() <= num) {
            int N = result.size();
            if (2 * N > num) N = num - N + 1;
            for (int i = 0; i < N; i++) {
                result.push_back(result[i] + 1);
            }
        }
        return result;
    }
};
// @lc code=end

