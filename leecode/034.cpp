/*
 * @Descripttion: 34. 在排序数组中查找元素的第一个和最后一个位置
        给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
        你的算法时间复杂度必须是 O(log n) 级别。
        如果数组中不存在目标值，返回 [-1, -1]。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-05-14 17:46:00
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-14 20:07:40
 */
#include <vector>
#include <iostream>
using namespace std;
//二分查找法（非递归）  8 ms 79.81%      8.1 MB  100.00%
vector<int> searchRange(vector<int>& nums, int target) {
    //获得左边边界
    int i=0,j=nums.size()-1;
    while(i<=j){
        int m=(i+j)/2;
        if(target<=nums[m])  j=m-1;
        else i=m+1;  
    }
    int left=i;
    if(left==nums.size() || nums[left]!=target) return {-1,-1};
    i=left+1;
    j=nums.size()-1;
    while(i<=j){
        int m=(i+j)/2;
        if(target<nums[m]) j=m-1;
        else if(target==nums[m]) i=m+1;
    }  
    int right=j;
    return {left,right};
}
int main(){
    vector<int> nums={1,2,3,4,5,5,5,6,6};
    vector<int> res=searchRange(nums,5);
    for(auto a:res)
        cout << a << " ";
}