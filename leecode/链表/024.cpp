/*
 * @Descripttion: 24. 两两交换链表中的节点
        给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
        你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * @version: 
 * @Author: Ye Yating
 * @Date: 2020-05-05 16:17:58
 * @LastEditors: Ye Yating
 * @LastEditTime: 2020-05-05 18:25:02
 */
#include <iostream>
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
/**
 * @name: 
 * @test: test font
 * @msg: 递归   4 ms   69.94%  6.4 MB  100.00%
 * @param {type} 
 * @return: 
 */
ListNode* swapPairs(ListNode* head)
{
    if(head==nullptr || head->next==nullptr)    return head;
    ListNode* next=head->next;
    head->next=swapPairs(next->next);
    next->next=head;
    return next;
}
int main()
{
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    ListNode* temp;
    temp = head;
    temp->val = 1;
    ListNode t2(2);
    temp->next = &t2;
    temp = temp->next;
    ListNode t3(3);
    temp->next = &t3;
    temp = temp->next;
    ListNode t4(4);
    temp->next = &t4;

    temp = swapPairs(head);
    while (temp->next != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << temp->val;
}