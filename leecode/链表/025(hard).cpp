/*
 * @Descripttion: 25. K 个一组翻转链表
        给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
        k 是一个正整数，它的值小于或等于链表的长度。
        如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * @version: 递归！递归！递归！
 * @Author: Ye Yating
 * @Date: 2020-05-05 18:25:36
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-07 15:48:26
 */
#include <iostream>
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
ListNode* func(ListNode* first, ListNode* second)
{
    ListNode* p=first;
    while(p->next!=second)
        p=p->next;
    p->next=second->next;
    second->next=first;
    return second;
}
ListNode* reverseK(ListNode* head){
    ListNode* cur=head;
    ListNode* pre=NULL;
    while(cur!=NULL){
        ListNode* next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    return pre;
}


ListNode* reverseKGroup(ListNode* head, int k)
{
    ListNode* dummy=new ListNode(-1);
    dummy->next=head;
    ListNode* pre=dummy;
    ListNode* end=dummy;

    while(end->next!=NULL){
        for(int i=0;i<k && end!=NULL;i++) end=end->next;
        if(end==NULL) break;
        ListNode* start=pre->next;
        ListNode* next=end->next;
        end->next=NULL;
        pre->next=reverseK(start);
        start->next=next;
        pre=start;

        end=pre;
    }
    return dummy->next;
}

int main(){
    ListNode* l1=(ListNode*)malloc(sizeof(ListNode));
    ListNode* temp;
    temp=l1;
    temp->val=1;
    temp->next=NULL;
    ListNode t2(2);
    temp->next=&t2;
    temp=temp->next;
    ListNode t3(3);
    temp->next=&t3;
    temp=temp->next;
    ListNode t4(4);
    temp->next=&t4;
    temp=temp->next;
    ListNode t5(5);
    temp->next=&t4;
    temp=temp->next;

    ListNode* head=reverseKGroup(l1,2);
    temp=head;
    while(temp->next!=NULL){
        cout << temp->val << " ";
        temp=temp->next;
    }
    cout << temp->val;
}
