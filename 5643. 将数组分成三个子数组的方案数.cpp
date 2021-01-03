#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int N = nums.size();
        int ret = 0;
        vector<int> presum(N + 1, 0);
        for (int i = 0; i < N; i++) presum[i + 1] = presum[i] + nums[i];
        int avg = presum[N] / 3 + 1;
        for (int l = 1, r = 2, rr = 2; l < N - 1; l++) {
            if (presum[l] > avg) break;
            while (r < N && presum[l] > presum[r] - presum[l]) r++;
            r = max(r, l + 1);
            if (r > rr) rr = r;
            while (rr < N && presum[N] - presum[rr] >= presum[rr] - presum[l]) rr++;
            ret += rr - r;
            if (ret >= 1000000007) ret -= 1000000007;
        }
        return ret;
    }
};

/* Test Main */
int main(void)
{
    Solution solve;
    vector<int> nums = {0,0,0,0};
    solve.waysToSplit(nums);
    return 0;
}
