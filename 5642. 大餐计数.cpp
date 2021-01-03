#include<algorithm>
#include<vector>
#include<limits>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int N = deliciousness.size();
        sort(deliciousness.begin(), deliciousness.end());
        unordered_map<int,int> mp;
        int ret = 0;
        for (int i = 0; i < N; i++) {
            if (deliciousness[i] != 0) {
                int sum = 1 << (32 - __builtin_clz(deliciousness[i]) - 1);
                ret += mp[sum - deliciousness[i]];
                ret += mp[(sum << 1) - deliciousness[i]];
                if (ret >= 1000000007) ret -= 1000000007;
            }
            mp[deliciousness[i]]++;
        }
        return ret;
    }
};

/* Test Main */
int main(void)
{
    Solution solve;
    vector<int> nums = {149,107,1,63,0,1,6867,1325,5611,2581,39,89,46,18,12,20,22,234};
    solve.countPairs(nums);
    return 0;
}
