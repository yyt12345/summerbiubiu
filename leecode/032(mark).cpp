/*
 * @Descripttion: 32. 最长有效括号
        给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-05-13 17:38:03
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-14 16:59:20
 */
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
//版本1.0   失败
int longestValidParentheses(string s) {
    if(s.size()==0) return 0;
    unsigned long maxN=0,count=0,index=-1;
    int temp=0;
    vector<int> pairNum;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')   temp++;
        else temp--;
        count++;
        if(temp==0){
            pairNum.push_back(count-temp);
            count=0;
            temp=0;
        }
        else if(temp==-1){
            unsigned long sum=0;
            for(int a:pairNum) sum+=a;
            pairNum.clear();
            maxN=max(maxN,sum);
            temp=0;
            count=0;
        }
    }
    if(temp!=-1) {
        unsigned long sum=0;
        for(int a:pairNum) sum+=a;
        maxN=max(maxN,sum);
        maxN=max(maxN,count-temp);
    }
    return maxN;
}
//版本2.0 动态规划
int longestValidParentheses2(string s) {
    int maxVal=0;
    vector<int> dp(s.size(),0);
    for(int i=1;i<s.size();i++){
        if(s.at(i)==')'){
            if(s.at(i-1)=='('){
                dp[i]=2;
                if(i>=2) dp[i]+=dp[i-2];
            }else if(dp[i-1]>0){
                if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-2]=='(') dp[i]=dp[i-1]+2+dp[i-dp[i-1]-2];
            }
        }
        maxVal=max(maxVal,dp[i]);
    }
    return maxVal;
}
int main(){
    int res=longestValidParentheses2(")()())");
    cout << res<<endl;
}
