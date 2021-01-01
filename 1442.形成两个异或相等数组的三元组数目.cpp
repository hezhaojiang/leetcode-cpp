/*
 * @lc app=leetcode.cn id=1442 lang=cpp
 *
 * [1442] 形成两个异或相等数组的三元组数目
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int N = arr.size();
        int res = 0;
        vector<int> preOR(N + 1, 0);
        for (int i = 0; i < N; i++) preOR[i + 1] = preOR[i] ^ arr[i];
        for (int i = 2; i < N + 1; i++) for (int j = 0; j < i - 1; j++) {
            if (preOR[i] == preOR[j]) res += i - j - 1;
        }
        return res;
    }
};
// @lc code=end

