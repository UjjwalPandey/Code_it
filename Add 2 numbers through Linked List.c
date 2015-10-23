Problem:
	https://www.interviewbit.com/courses/programming/topics/linked-lists/problems/addnum/
	You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Solution:

/**
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
 * @input B : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
int getCount(listnode *p){
    listnode *a =p;
    int d =0;
    while(a!=NULL){
        d++;
        a =a->next;
    }
    return d;
}
listnode* sum(listnode* A, int a, listnode* B, int b){
    int d = 0;
    listnode *temp=NULL, *ans=NULL, *p=NULL;
    int sum,carry=0;
    while(d<b){
        
        sum = A->val+B->val+carry;
        
        if(sum > 9){
            temp = listnode_new(sum%10);
        }else{
            temp = listnode_new(sum);
        }
            if(carry != 0){
                carry =0;
            }
            carry = sum/10;
            if(d==0){
                ans= p= temp;
            }else{
                p->next = temp;
                p = temp ;
            }
        A=A->next;
        B = B->next;
        d++;
    }
    while(d<a){
        sum = A->val+carry;
         if(sum > 9){
            temp = listnode_new(sum%10);
        }else{
            temp = listnode_new(sum);
        }
            if(carry != 0){
                carry =0;
            }
            carry = sum/10;
            if(d==0){
                 p= temp;
            }else{
                p->next = temp;
                p = temp ;
            }
        A=A->next;
        B = B->next;
        d++;
    }
    if(carry != 0){
        p->next = listnode_new(carry);
    }
    return ans;
}

listnode* addTwoNumbers(listnode* A, listnode* B) {
    int a, b;
    a = getCount(A);
    b = getCount(B);
    if(a>=b){
        return sum(A,a,B,b);
    }
    return sum(B,b,A,a);
}
