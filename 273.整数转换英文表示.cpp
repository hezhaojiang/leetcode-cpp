/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 */
#include<string>
#include<unordered_map>
using namespace std;
// @lc code=start
#define HUNDRED (100)
#define THOUSAND (1000)
#define MILLION (1000000)
#define BILLION (1000000000)

class Solution {
private:
    unordered_map<int,string> Digit;
    unordered_map<int,string> Unit;
    string Convert(int num) {
        string strRet = ""; 
        if(0 == num)
            return strRet;
        if(num < 10)
            strRet += " " + Digit[num];
        else if(num < 20)
            strRet += " " + Digit[num];
        else if(num < HUNDRED)
            strRet += " " + Digit[num - num%10] + Convert(num%10);
        else if(num < THOUSAND)
            strRet += Convert(num/HUNDRED) + " " + Unit[HUNDRED] + Convert(num%HUNDRED);
        else if(num < MILLION)
            strRet += Convert(num/THOUSAND) + " " + Unit[THOUSAND] + Convert(num%THOUSAND);
        else if(num < BILLION)
            strRet += Convert(num/MILLION) + " " + Unit[MILLION] + Convert(num%MILLION);
        else
            strRet += Convert(num/BILLION) + " " + Unit[BILLION] + Convert(num%BILLION);
        return strRet;
    }
public:
    Solution()
    {
        Digit.insert({
            {1,"One"},{2,"Two"},{3,"Three"},{4,"Four"},{5,"Five"},
            {6,"Six"},{7,"Seven"},{8,"Eight"},{9,"Nine"}
        });
        Digit.insert({
            {11,"Eleven"},{12,"Twelve"},{13,"Thirteen"},{14,"Fourteen"},{15,"Fifteen"},
            {16,"Sixteen"},{17,"Seventeen"},{18,"Eighteen"},{19,"Nineteen"}
        });
        Digit.insert({
            {10,"Ten"},{20,"Twenty"},{30,"Thirty"},{40,"Forty"},{50,"Fifty"},
            {60,"Sixty"},{70,"Seventy"},{80,"Eighty"},{90,"Ninety"}
        });
        Unit.insert({
            {HUNDRED,"Hundred"},{THOUSAND,"Thousand"},{MILLION,"Million"},{BILLION,"Billion"}
        });
    }
    string numberToWords(int num) {
        string strRet = ""; 
        if (0 == num)
            return "Zero";   
        strRet = Convert(num);
        /*去掉首位空格*/
        strRet.erase(0,1);
        return strRet;
    }
};
// @lc code=end

