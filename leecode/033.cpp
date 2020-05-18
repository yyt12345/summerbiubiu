/*
 * @Descripttion: 33. 搜索旋转排序数组
        假设按照升序排序的数组在预先未知的某个点上进行了旋转。
        ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
        搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
        你可以假设数组中不存在重复的元素。
        你的算法时间复杂度必须是 O(log n) 级别。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-05-14 17:04:52
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-14 17:45:52
 */
#include <vector>
#include <iostream>
using namespace std;
//0 ms  100.00%     6.4 MB  100.00%
int dAndC(vector<int>& nums,int start,int end,int target){
    if(start==end && nums[start]!=target) return -1;
    if(target==nums[(start+end)/2]) return (start+end)/2;
    else if(target<nums[(start+end)/2])
        return dAndC(nums,start,(start+end)/2,target);
    else
        return dAndC(nums,(start+end+1)/2,end,target);
}
int search(vector<int>& nums, int target) {
    if(nums.size()==0) return -1;
    int bound=0;
    for(int i=1;i<nums.size();i++){
        if(nums[i-1]>nums[i]){
            bound=i;
            break;
        }
    }
    if(bound==0) return dAndC(nums,0,nums.size()-1,target);
    if(target<nums[0])
        return dAndC(nums,bound,nums.size()-1,target);
    else
        return dAndC(nums,0,bound-1,target);
}
int main(){
    vector<int> nums={1};
    int res=search(nums,2);
    cout << res << endl;
}