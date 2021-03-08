/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
#define LL long long
class Solution {
private:
    const int mod = 1e9 + 7;
    bool checkFindLength(vector<int>& A, vector<int>& B, int len) {
        if (len == 0) return true;
        // 遍历 A 的子数组
        unordered_map<int, vector<int>> Amp;
        int i = 0, svalue = 0, df = 1;
        for (; i < len - 1; i++) {
            svalue = ((LL)svalue * 31 + A[i]) % mod;
            df = ((LL)df * 31) % mod;
        }
        for (; i < A.size(); i++) {
            if (i >= len) svalue = (((LL)svalue - (LL)df * A[i - len]) % mod + mod) % mod;
            svalue = ((LL)svalue * 31 + A[i]) % mod;
            Amp[svalue].push_back(i - len + 1);
        }

        // 遍历 B 的子数组
        i = 0, svalue = 0;
        for (; i < len - 1; i++) svalue = ((LL)svalue * 31 + B[i]) % mod;
        for (; i < B.size(); i++) {
            if (i >= len) svalue = (((LL)svalue - (LL)df * B[i - len]) % mod + mod) % mod;
            svalue = ((LL)svalue * 31 + B[i]) % mod;
            int index = i - len + 1;
            if (Amp.count(svalue)) {
                // 检查哈希碰撞
                for (auto start : Amp[svalue]) {
                    // cout << "len:" << len << ", Aindex:" << start << ", Bindex:" << index << endl;
                    bool isSame = true;
                    for (int j = 0; j < len; j++) {
                        if (A[start + j] != B[index + j]) {
                            isSame = false;
                            break;
                        }
                    }
                    if (isSame) return true;
                }
            }
        }
        return false;
    }

public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        int l = 0, r = min(n, m);
        while (l <= r) {
            int mid = l + r >> 1;
            if (checkFindLength(A, B, mid)) l = mid + 1;
            else r = mid - 1;
        }
        return r;
    }
};
// @lc code=end
