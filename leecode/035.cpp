/*
 * @Descripttion: 35. 搜索插入位置
        给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
        你可以假设数组中无重复元素。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-05-14 20:07:49
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-15 11:31:49
 */
#include <vector>
#include <iostream>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
    if(nums.size()==0) return 0;
    int i=0,j=nums.size()-1;
    while(i<j){
        int m=(i+j)/2;
        if(target==nums[m]) return m;
        else if(target<nums[m]) j=m;
        else i=m+1;
    }
    if(i==j && nums[i]<target) return i+1;
    else if(i==j && nums[i]>target) return i;
}
int main(){
    vector<int> nums={1,3,5,6};
    int res=searchInsert(nums,2);
    cout << res << endl;
}
