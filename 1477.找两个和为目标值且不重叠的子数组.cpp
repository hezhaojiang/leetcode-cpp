/*
 * @lc app=leetcode.cn id=1477 lang=cpp
 *
 * [1477] 找两个和为目标值且不重叠的子数组
 */
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int N = arr.size();
        if (N < 0) return -1;
        vector<int> prefix(N , N), suffix(N, N);
        unordered_map<int, int> preMp, sufMap;
        preMp[0] = -1; sufMap[0] = N;
        for (int i = 0, sum = 0, last = N; i < N; i++) {
            sum += arr[i];
            if (preMp.find(sum - target) != preMp.end())
                last = min(last, i - preMp[sum - target]);
            preMp[sum] = i;
            prefix[i] = last;
        }
        if (prefix[N - 1] == N) return -1;
        for (int i = N - 1, sum = 0, last = N; i >= 0; i--) {
            sum += arr[i];
            if (sufMap.find(sum - target) != sufMap.end())
                last = min(last, sufMap[sum - target] - i);
            sufMap[sum] = i;
            suffix[i] = last;
        }
        int minlength = N + 1;
        for (int i = 1; i < N; i++) {
            minlength = min(minlength, prefix[i - 1] + suffix[i]);
        }
        return minlength == N + 1 ? -1 : minlength;
    }
};
// @lc code=end

