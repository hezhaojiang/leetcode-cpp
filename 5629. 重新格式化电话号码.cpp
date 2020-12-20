#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string reformatNumber(string number) {
        /* 去 '-' 和 ' ' */
        int i = 0, j = 0;
        for (i = 0, j = 0; j < number.size(); j++) {
            if (number[j] == '-' || number[j] == ' ') continue;
            number[i++] = number[j];
        }
        number = number.substr(0, i);
        
        int N = number.size();
        string ret;
        for (i = 0; i < N; i++) {
            if (i != 0 && i % 3 == 0 && i != N - 1) ret.push_back('-');
            else if (i != 0 && N % 3 == 1 && i == N - 2) ret.push_back('-');
            ret.push_back(number[i]);
        }
        return ret;
    }
};

/* Test Main */
int main(void)
{
    Solution solve;
    solve.reformatNumber("1234-567");
    return 0;
}
