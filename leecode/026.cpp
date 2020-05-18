/*
 * @Descripttion: 26. 删除排序数组中的重复项
          给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
          不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
 * @version:16 ms   80.67%  7.9 MB  100.00%
 * @Author: Ye Yating
 * @Date: 2020-05-07 15:49:01
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-07 16:03:55
 */
#include <vector>
#include <iostream>
using namespace std;
int removeDuplicates(vector<int>& nums)
{
    if(nums.size()==0) return NULL;
    int index = 0;
    for (int i = 1; i < nums.size(); i++) {
        if(nums[i]==nums[index]) continue;
        else    nums[++index]=nums[i];
    }
    nums.resize(index+1);
    return index+1;
}
int main(){
    vector<int> nums={1,1,2,3,3,4};
    int len=removeDuplicates(nums);
    cout<<len<<endl;
    for(int a:nums){
        cout << a << endl;
    }
}