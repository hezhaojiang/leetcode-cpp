/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<string> result;
    vector<int> ipseg;
    void dfs(string &s, int segidx, int stridx)
    {
        if (segidx == 4)
        {
            if (stridx == s.length()) {
                string ipStr = "";
                for (int i = 0; i < ipseg.size(); i++) {
                    ipStr += to_string(ipseg[i]);
                    if (i != ipseg.size() - 1) ipStr += ".";
                }
                result.push_back(ipStr);
            }
            return;
        }
        if (stridx == s.length()) {
            return;
        }

        if (s[stridx] == '0') { // 由于不能有前导零，如果当前数字为 0，那么这一段 IP 地址只能为 0
            ipseg[segidx] = 0;
            dfs(s, segidx + 1, stridx + 1);
        }

        int addr = 0; // 一般情况，枚举每一种可能性并递归
        for (int strend = stridx; strend < s.length() && strend - stridx < 3; ++strend) {
            addr = addr * 10 + (s[strend] - '0');
            if (addr > 0 && addr <= 0xFF) {
                ipseg[segidx] = addr;
                dfs(s, segidx + 1, strend + 1);
            } 
            else {
                break;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        ipseg.resize(4);
        dfs(s, 0, 0);
        return result;
    }
};
// @lc code=end

