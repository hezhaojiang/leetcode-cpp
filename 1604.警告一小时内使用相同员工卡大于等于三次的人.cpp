/*
 * @lc app=leetcode.cn id=1604 lang=cpp
 *
 * [1604] 警告一小时内使用相同员工卡大于等于三次的人
 */
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<string>> mp;  //统计每个名字的各个时间
        for (int i = 0; i < keyName.size(); ++i) mp[keyName[i]].push_back(keyTime[i]);
        for (auto& it : mp) sort(it.second.begin(), it.second.end());
        vector<string> res;  //存储结果数组
        for (auto& it : mp) {
            vector<string>& cur_times = it.second;
            for (int i = 2; i < cur_times.size(); ++i) {  //判断相邻的三个时间是否在一个小时之内
                int diff = (stoi(cur_times[i].substr(0, 2)) - stoi(cur_times[i - 2].substr(0, 2))) * 60 +
                    (stoi(cur_times[i].substr(3)) - stoi(cur_times[i - 2].substr(3)));
                if (diff <= 60) {
                    res.push_back(it.first);
                    break;
                }
            }
        }
        //对结果进行排序
        sort(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
