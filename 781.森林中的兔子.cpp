/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int last = 0, rest = 0, num = 0;
        sort(answers.begin(), answers.end());
        for (int i = 0; i < answers.size(); i++) {
            if (rest == 0 || last != answers[i]) {
                last = answers[i];
                rest = answers[i];
                num += answers[i] + 1;
            }
            else {
                last = answers[i];
                rest--;
            }
        }
        return num;
    }
};
// @lc code=end

