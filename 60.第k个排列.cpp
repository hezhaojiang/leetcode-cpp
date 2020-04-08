/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
private:
    int index;
    vector<int> flag;
    vector<int> item;
    string result;
public:
    string getPermutation(int n, int k)
    {
        item.push_back(1);
        flag.push_back(1);
        for (int i = 1; i < n; i++)
        {
            item.push_back(i * item.back());
            flag.push_back(1);
        }

        k = k - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            int idx = 0;
            int orange = k / item[i];
            k = k % item[i];
            for (int j = 0; j < n; j++)
            {
                if (idx == orange && flag[j] != 0)
                {
                    result = result + to_string(j + 1);
                    flag[j] = 0;
                    break;
                }
                if (flag[j] != 0)
                {
                    idx++;
                }
            }
        }
        return result;
    }
};
// @lc code=end
int main()
{
    Solution solve;
    cout << solve.getPermutation(3,3) << endl;
    return 0;
}


