/*
 * @Descripttion: 29. 两数相除
        给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
        返回被除数 dividend 除以除数 divisor 得到的商。
        整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
 * @version: 0 ms   100.00%     6.2 MB  100.00%
 * @Author: Ye Yating
 * @Date: 2020-05-07 20:34:06
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-10 18:33:37
 */
#include <algorithm>
#include <iostream>
using namespace std;
long subdiv(long dividend, long divisor) {
    int n=0;

    if(dividend<divisor) return 0;
    else if(dividend==divisor) return 1;
    else{
        int count=0;
        long div2=divisor; 
        while(dividend>div2){
            div2=div2<<1;
            count++;
        }
        if(div2==dividend) return pow(2,count);
        n+=pow(2,count-1);
        n+=subdiv(dividend-n*divisor,divisor);
    }
    return n;
}
int divide(int dividend,int divisor){
    int flag=1;
    if((long)dividend*divisor>0) flag=1;
    else flag=-1;
    long a=dividend>0?dividend:(-1)*(long)dividend;
    long b=divisor>0?divisor:(-1)*(long)divisor;
    long res=subdiv(a,b);
    if(flag==1) return res>INT32_MAX?INT32_MAX:res;
    else return -res;
}
int main(){
    int res=divide(7,-3);
    long dividend=-2147483648;
    dividend=dividend>0?dividend:-dividend;
    cout << res;
}

