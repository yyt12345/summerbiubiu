/*
 * @Descripttion: 38. 外观数列
        「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：

        1.     1
        2.     11
        3.     21
        4.     1211
        5.     111221
        1 被读作  "one 1"  ("一个一") , 即 11。
        11 被读作 "two 1s" ("两个一"）, 即 21。
        21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

        给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-05-17 11:07:45
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-17 12:01:20
 */ 
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//  8 ms    48.10%      6.3 MB  100.00%
string countAndSay(int n) {
    string cur,pre;
    pre="1";
    if(n==1) return pre;
    for(int i=2;i<=n;i++){
        cur="";
        int index=0;
        int j;
        for(j=1;j<pre.size();j++){
            if(pre[j]!=pre[index]){
                cur+=j-index+'0';
                cur+=pre[index];
                index=j;
            }
        }
        cur+=j-index+'0';
        cur+=pre[index];
        pre=cur;
    }
    return cur;
}
int main(){
    cout << countAndSay(5) << endl;
}