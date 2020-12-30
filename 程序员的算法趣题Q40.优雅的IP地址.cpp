#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
private:
    int int_8_reverse(int num) {
        num = num & 0xff;
        num = (num >> 4) | (num << 4);
        num = ((num & 0xcc) >> 2) | ((num & 0x33) << 2);
        num = ((num & 0xaa) >> 1) | ((num & 0x55) << 1);
        return num;
    }

    bool have_same_digist(int num1, int num2) {
        vector<int> m(10, 0);
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        for (auto c : s1) if (m[c - '0']++ != 0) return true;
        for (auto c : s2) if (m[c - '0']++ != 0) return true;
        return false;
    }

    int bit_mask_num(int num) {
        int ret = 0;
        while (num > 0) {
            int n = num % 10;
            num /= 10;
            ret |= 1 << n;
        }
        return ret;
    }

public:
    vector<string> elegantIpAddress() {
        vector<string> ans;
        vector<pair<int, int>> rvsNum;
        for (int num = 0; num < 256; num++) {
            int rvs = int_8_reverse(num);
            if (!have_same_digist(num, rvs)) {
                rvsNum.push_back({num, bit_mask_num(num) | bit_mask_num(rvs)});
            }
        }

        int N = rvsNum.size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if ((rvsNum[i].second | rvsNum[j].second) == 0x03FF) {
                    ans.push_back(to_string(rvsNum[i].first) + "." + to_string(rvsNum[j].first) + "." +
                        to_string(int_8_reverse(rvsNum[j].first)) + "." + to_string(int_8_reverse(rvsNum[i].first)));
                }
            }
        }        
        return ans;
    }
};

/* Test Main */
int main(void)
{
    Solution solve;
    solve.elegantIpAddress();
    return 0;
}
