/*
Problem:

Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Solution:
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * @input m : Integer
 * @input n : Integer
 * 
 * @Output head pointer of list.
 */
listnode* reverseBetween(listnode* A, int m, int n) {
    if(A==NULL || A->next==NULL || (m==n)){
        return A;
    }
    int i;
    listnode *temp,  *pre, *ptr, *newhead =listnode_new(-1);
    newhead->next = A;
    temp=pre = newhead;
    for(i=0; i<m-1;i++){
        pre=pre->next;
    }
    ptr = pre;
    pre = pre->next;
    temp = pre->next;
    for(i=m;i<n;i++){
        pre->next = temp->next;
        temp->next = ptr->next;
        ptr->next = temp;
        temp = pre->next;
    }
    return newhead->next;
}
