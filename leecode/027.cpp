/*
 * @Descripttion: 27. 移除元素
        给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
        不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
        元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 * @version: 0 ms  100.00% 6.5 MB  100.00%
 * @Author: Ye Yating
 * @Date: 2020-05-07 16:04:07
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-11 16:40:21
 */
#include <vector>
#include <iostream>
using namespace std;
int removeElement(vector<int>& nums, int val) {
    nums.push_back(INT16_MAX);
    for(vector<int>::iterator it=nums.begin();it!=nums.end();){
        if(*(it)==val) nums.erase(it);
        else it++;
    }
    return nums.size()-1;
}
int main(){
    vector<int> nums={0,1,2,2,3,0,4,2};
    int len=removeElement(nums,2);
    cout<<len<<endl;
    for(int a:nums){
        cout << a << endl;
    }
}