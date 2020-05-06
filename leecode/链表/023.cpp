/*
 * @Descripttion: 
 * @version: 021>023
 * @Author: Ye Yating
 * @Date: 2020-05-05 15:22:41
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-06 10:03:41
 */

/*
23. 合并K个排序链表
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
*/
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
};
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if (l1 == nullptr)
        return l2;
    else if (l2 == nullptr)
        return l1;
    else if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

//逐个合并 	348 ms	10.6 MB
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size()==0) return NULL;
    ListNode* res=lists[0];
    for(int i=1;i<lists.size();i++){
        res=mergeTwoLists(res,lists[i]);
    }
    return res;
}

//分治法    32 ms	10.4 MB
ListNode* merge(vector<ListNode*>& lists,int l,int r){
    if(l==r) return lists[l];
    else if(l>r ) return nullptr;
    int mid=(r+l)>>1;
    return mergeTwoLists(merge(lists,l,mid),merge(lists,mid+1,r));
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
    return merge(lists,0,lists.size()-1);
}
