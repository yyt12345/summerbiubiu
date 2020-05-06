/*
    给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
*/
#include <string>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

int longestPalindrome(string s)
{
    int count = 0;
    vector<char> res;
    map<char, int> hash;
    for (auto a : s)
    {
        hash[a]++;
    }
    bool first = true;
    for (map<char, int>::iterator iter = hash.begin(); iter != hash.end();)
    {
        if ((*iter).second >= 2)
        {
            count += 2;
            (*iter).second -= 2;
        }
        else if (first == true && (*iter).second % 2 == 1)
        {
            count++;
            first = false;
        }
        else
        {
            iter++;
        }
    }
    return count;
}
