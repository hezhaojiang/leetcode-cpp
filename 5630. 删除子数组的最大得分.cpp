#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int nowSum = 0;
        int maxResult = 0;
        int N = nums.size();
        unordered_map<int,int> mp;
        for (int i = 0, j = 0; j < N; j++) {
            if (mp[nums[j]] != 0) {
                do {
                    nowSum -= nums[i];
                    mp[nums[i]] = 0;
                } while (nums[i++] != nums[j]);
            }
            mp[nums[j]] = 1;
            nowSum += nums[j];
            maxResult = max(nowSum, maxResult);
        }
        return maxResult;
    }
};

/* Test Main */
int main(void)
{
    Solution solve;
    vector<int> nums{187,470,25,436,538,809,441,167,477,110,275,133,666,345,411,459,490,266,987,965,429,166,809,340,467,318,125,165,809,610,31,585,970,306,42,189,169,743,78,810,70,382,367,490,787,670,476,278,775,673,299,19,893,817,971,458,409,886,434};
    solve.maximumUniqueSubarray(nums);
    return 0;
}