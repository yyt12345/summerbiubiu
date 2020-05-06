/*
21. 合并两个有序链表
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//20 ms 13.02%  7.2 MB 100.00%          时间复杂度 O(m+n)
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // if(l1==nullptr && l2==nullptr) return NULL;
    // else if(l1==nullptr) return l2;
    // else if (l2==nullptr) return l1;

    ListNode* preHead = new ListNode(-1);
    // if(l1->val <= l2->val) head=l1;
    // else head=l2;
    ListNode* t=preHead;
    while(l1!=nullptr && l2!=nullptr){
        if(l1->val <= l2->val){
            t->next=l1;
            l1=l1->next;
        }else{
            t->next=l2;
            l2=l2->next;
        }
        t=t->next;
    }
    t->next= l1 == nullptr ? l2 : l1;
    return preHead->next;
}

//使用递归法  20 ms 13.02% 7.1 MB 100.00%
ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
    if(l1==nullptr) return l2;
    else if(l2==nullptr) return l1;
    else if(l1->val < l2->val){
        l1->next=mergeTwoLists(l1->next,l2);
        return l1;
    }else{
        l2->next=mergeTwoLists(l1,l2->next);
        return l2;
    }
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
    ListNode t3(4);
    temp->next=&t3;

    ListNode* l2=(ListNode*)malloc(sizeof(ListNode));
    temp=l2;
    temp->val=1;
    temp->next=NULL;
    ListNode t4(3);
    temp->next=&t4;
    temp=temp->next;
    ListNode t5(4);
    temp->next=&t5;

    ListNode* head=mergeTwoLists(l1,l2);
    temp=head;
    while(temp->next!=NULL){
        cout << temp->val << " ";
        temp=temp->next;
    }
    cout << temp->val;
}