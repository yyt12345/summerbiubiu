/*
19. 删除链表的倒数第N个节点
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 4ms(89.0%) 6.8MB(100%)
ListNode* removeNthFromEnd(ListNode* head, int n) {
    vector<ListNode*> list;
    ListNode* p=head;
    list.push_back(p);
    while (p->next!=NULL)
    {
        p=p->next;
        list.push_back(p);
    }
    if(list.size()==1 && n==1) return NULL;
    //删除第一个
    if(n==list.size()){
        return list[1];
    }else{
        p=list[list.size()-n-1];
        p->next=p->next->next;
    }
    return list[0];

}

int main(){
    ListNode* head=(ListNode*)malloc(sizeof(ListNode));
    ListNode* temp;
    temp=head;
    temp->val=1;
    temp->next=NULL;
    // ListNode t2(2);
    // temp->next=&t2;
    // temp=temp->next;
    // ListNode t3(3);
    // temp->next=&t3;
    // temp=temp->next;
    // ListNode t4(4);
    // temp->next=&t4;


    temp=removeNthFromEnd(head,1) ;
    while(temp->next!=NULL){
        cout << temp->val << " ";
        temp=temp->next;
    }
    cout << temp->val;

}