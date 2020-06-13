/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>* s;
        vector<int>* l;
        unordered_map<int, int> Hashnum;
        vector<int> result;
        if(nums1.size() < nums2.size()) 
        {
            s = &nums1;
            l = &nums2;
        }
        else
        {
            s = &nums1;
            l = &nums2;
        }

        for(auto i : *s)
        {
            if(Hashnum.find(i) != Hashnum.end())
                Hashnum[i] = Hashnum[i] + 1;
            else
                Hashnum[i] = 1;
        }

        for(auto i : *l)
        {
            if(Hashnum.find(i) != Hashnum.end() && Hashnum[i] != 0)
            {
                result.emplace_back(i);
                Hashnum[i] = Hashnum[i] - 1;
            }
                
        }
        
        return result;
    }
};
// @lc code=end

