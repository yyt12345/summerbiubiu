/*
22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator>
using namespace std;

string s = "()";
map<string, int> maps;

//使用递归的方式，以（）为单位插入
//64 ms 5.38% 10.1 MB 86.05%
void insertStr(string str, int level, int n)
{
    for (int i = 0; i < str.size() / 2 + 1; i++)
    {
        string temp = str;
        temp.insert(i, s);
        if (level == n)
        {
            maps[temp] = 1;
            continue;
        }
        insertStr(temp, level + 1, n);
    }
}
vector<string> generateParenthesis(int n)
{
    insertStr("", 1, n);
    vector<string> result;
    map<string, int>::iterator it;
    for (it = maps.begin(); it != maps.end(); it++)
    {
        result.push_back(it->first);
    }
    return result;
}

//回溯算法（深度优先遍历） 4 ms  89.83%    17 MB   51.16%
vector<string> res;
void func(string str,int l,int r){
    if(r<l || r<0 || l<0) return;
    if(r==0 && l==0) {
        res.push_back(str);
        return;
    }
    func(str+'(',l-1,r);
    func(str+')',l,r-1);
    return;
}
vector<string> generateParenthesis2(int n)
{
    func("",n,n);
    return res;
}

//动态规划  4 ms    89.83%  7.6 MB  100.00%
vector<string> generateParenthesis3(int n)
{
    vector<vector<string> > dp;
    //初始状态
    vector<string> dp0;
    dp0.push_back("");
    dp.push_back(dp0);
    for(int i=1;i<=n;i++){
        vector<string> cur;
        for(int j=0;j<i;j++){
            for(string str1:dp[j]){
                for(string str2:dp[i-j-1]){
                    cur.push_back('('+str1+')'+str2);
                }
            }
        }
        dp.push_back(cur);
    }
    return dp[n];
}
int main()
{
    vector<string> a = generateParenthesis3(3);
    for (auto n : a)
    {
        cout << n << endl;
    }
}