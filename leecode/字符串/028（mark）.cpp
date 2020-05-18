/*
 * @Descripttion: 28. 实现 strStr()
        给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串
        出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
 * @version: 典型的字符匹配算法
 * @Author: Ye Yating
 * @Date: 2020-05-07 16:26:04
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-07 20:26:33
 */
#include <string>
#include <iostream>
using namespace std;
/**
 * @name: 
 * @test: test font
 * @msg: 移动窗口，逐串比较
 * 84 ms    12.75%  643.6 MB    5.77%
 * @param {type} 
 * @return: 
 */
int strStr(string haystack, string needle) {
    int needle_size=needle.size(),haystack_size=haystack.size();
    if(needle_size==0) return 0;
    if(needle_size>haystack_size) return -1;
    for(int i=0;i<haystack_size;i++){
        if(haystack[i]==needle[0]){
            if(haystack.substr(i,needle_size)==needle) return i;
        }
    }
    return -1;
}
//KMP查询算法
void GetNext(int* next,string P){
    int p_len = P.size();
    int i = 0;   // P 的下标
    int j = -1;  
    next[0] = -1;

    while (i < p_len)
    {
        if (j == -1 || P[i] == P[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int strStr2(string haystack, string needle) {
    int next[needle.size()];
    GetNext(next,needle);

    int i = 0;  // S 的下标
    int j = 0;  // P 的下标
    int haystack_len = haystack.size();
    int needle_len = needle.size();

    while (i < haystack_len && j < needle_len) // 因为末尾 '\0' 的存在，所以不会越界
    {
        if (j == -1 || haystack[i] == needle[j])  // P 的第一个字符不匹配或 S[i] == P[j]
        {
            i++;
            j++;
        }
        else
            j = next[j];  // 当前字符匹配失败，进行跳转
    }

    if (j == needle_len)  // 匹配成功
        return i - j;
    
    return -1;
}
int main(){
    int res=strStr2("hello","ll");
    cout << res<< endl;
}