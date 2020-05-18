/*
 * @Descripttion: 31. 下一个排列
        实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
        如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
        必须原地修改，只允许使用额外常数空间。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-05-13 16:18:21
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-13 17:39:37
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//4 ms	12.2 MB
void nextPermutation(vector<int>& nums) {
    int i,j;
    for(i=nums.size()-1;i>0;i--){
        if(nums[i-1]<nums[i]){
            for(j=i;j<nums.size();j++){
                if(nums[j]<=nums[i-1]) {
                    int temp=nums[j-1];
                    nums[j-1]=nums[i-1];
                    nums[i-1]=temp;
                    break;
                }
            }
            if(j==nums.size()){
                int temp=nums[i-1];
                nums[i-1]=nums[j-1];
                nums[j-1]=temp;
            }
            reverse(nums.begin()+i,nums.end());
            break;
        }
    }
    if(i==0) reverse(nums.begin(),nums.end());
    return ;
}
//12 ms	12.1 MB
void nextPermutation2(vector<int>& nums) {
    int pos=nums.size()-1;
    while(pos>0 && nums[pos]<=nums[pos-1])
        pos--;
    reverse(nums.begin()+pos,nums.end());
    if(pos>0){
        int start=pos;
        for(;start<nums.size();start++){
            if(nums[start]>nums[pos-1]){
                swap(nums[start],nums[pos-1]);
                break;
            }
        }
    }
    return ;
}
int main(){
    vector<int> nums={4,3,2,1};
    nextPermutation(nums);
    for(auto a:nums){
        cout << a << endl;
    }
}
