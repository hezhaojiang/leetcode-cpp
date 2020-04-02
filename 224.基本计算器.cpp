/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
#define STATE_BEGIN 0
#define STATE_NUMBER 1
#define STATE_SYMBOL 2

class Solution {
public:
    int calculate(string s) 
    {
        std::stack<char> symbol;
        std::stack<int> number;

        int state = STATE_BEGIN;
        int num = 0;

        for (int i = 0; i < s.size(); i++)
        {
            switch (state)
            {
                case STATE_BEGIN:
                {
                    if (s[i] >= '0' && s[i] <= '9')
                    {
                        num = s[i] - '0';
                        state = STATE_NUMBER;
                    }
                    else if ('(' == s[i])
                    {
                        symbol.push(s[i]);
                        state = STATE_SYMBOL;
                    }
                    break;
                }
                case STATE_NUMBER:
                {
                    if (s[i] >= '0' && s[i] <= '9')
                    {
                        num = 10 * num + s[i] - '0';
                    }
                    else if ('-' == s[i] || '+' == s[i])
                    {
                        if (!symbol.empty() && ('+' == symbol.top() || '-' == symbol.top()))
                        {
                            if ('+' == symbol.top())
                            {
                                num = number.top() + num;
                                number.pop();
                                number.push(num);
                                symbol.pop();
                                symbol.push(s[i]);
                            }
                            else if ('-' == symbol.top())
                            {
                                num = number.top() - num;
                                number.pop();
                                number.push(num);
                                symbol.pop();
                                symbol.push(s[i]);
                            }
                            else
                            {
                                symbol.push(s[i]);
                            }
                        }
                        else
                        {
                            symbol.push(s[i]);
                            number.push(num);
                        }
                        state = STATE_SYMBOL;
                    }
                    else if ('(' == s[i])
                    {
                        symbol.push(s[i]);
                        state = STATE_SYMBOL;
                    }
                    else if (')' == s[i])
                    {
                        if ('+' == symbol.top())
                        {
                            num = number.top() + num;
                            number.pop();
                            number.push(num);
                            symbol.pop();
                        }
                        else if ('-' == symbol.top())
                        {
                            num = number.top() - num;
                            number.pop();
                            number.push(num);
                            symbol.pop();
                        }
                        symbol.pop();
                        if(!symbol.empty() && ('+' == symbol.top() || '-' == symbol.top()))
                        {
                            if ('+' == symbol.top())
                            {
                                num = number.top();
                                number.pop();
                                num = number.top() + num;
                                number.pop();
                                symbol.pop();
                                number.push(num);
                            }
                            else if ('-' == symbol.top())
                            {
                                num = number.top();
                                number.pop();
                                num = number.top() - num;
                                number.pop();
                                symbol.pop();
                                number.push(num);
                            }
                        }
                    state = STATE_SYMBOL;
                    }
                    break;
                }
                case STATE_SYMBOL:
                {
                    if (s[i] >= '0' && s[i] <= '9')
                    {
                        num = s[i] - '0';
                        state = STATE_NUMBER;
                    }
                    else if ('-' == s[i] || '+' == s[i])
                    {
                        if (!symbol.empty() && ('+' == symbol.top() || '-' == symbol.top()))
                        {
                            if ('+' == symbol.top())
                            {
                                num = number.top();
                                number.pop();
                                num = number.top() + num;
                                number.pop();
                                symbol.pop();
                                number.push(num);
                                symbol.push(s[i]);
                            }
                            else if ('-' == symbol.top())
                            {
                                num = number.top();
                                number.pop();
                                num = number.top() - num;
                                number.pop();
                                symbol.pop();
                                number.push(num);
                                symbol.push(s[i]);
                            }
                            else
                            {
                                symbol.push(s[i]);
                            }
                        }
                        else
                        {
                            symbol.push(s[i]);
                        }
                        state = STATE_SYMBOL;
                    }
                    else if ('(' == s[i])
                    {
                        symbol.push(s[i]);
                    }
                    break;
                }
                default:
                {
                    break;
                }
            }
        }

        if ('+' == symbol.top())
        {
            num = number.top() + num;
            number.pop();
            number.push(num);
            symbol.pop();
        }
        else if ('-' == symbol.top())
        {
            num = number.top() - num;
            number.pop();
            number.push(num);
            symbol.pop();
        }
        return number.top();
    }
};
// @lc code=end

