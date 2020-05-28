/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        int numCount[2][10] = {0};
        int Bulls = 0;
        int Cows = 0;
        for(int i = 0; i < secret.length(); i++)
        {
            if(secret[i] == guess[i])
                Bulls++;
            else
            {
                numCount[0][secret[i] - '0']++;
                numCount[1][guess[i] - '0']++;
            }
        }
        for(int i = 0; i < 10; i++)
        {
            Cows += min(numCount[0][i], numCount[1][i]);
        }
        return to_string(Bulls) + "A" + to_string(Cows) + "B";
    }
};
// @lc code=end

