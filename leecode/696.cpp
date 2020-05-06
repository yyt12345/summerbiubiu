/*
696. 计数二进制子串
给定一个字符串 s，计算具有相同数量0和1的非空(连续)子字符串的数量，并且这些子字符串中的所有0和所有1都是组合在一起的。

重复出现的子串要计算它们出现的次数。
*/
#include <string>

using namespace std;

int countBinarySubstrings(string s)
{
    int n = 0, pre = 0, cur = 1, len = s.size() - 1;
    for (int i = 0; i < len; i++)
    {
        if (s.at(i) == s.at(i + 1))
            cur++;
        else
        {
            n+=min(pre,cur);
            pre = cur;
            cur = 1;
        }
    }
    n+=min(pre,cur);
    return n;
}