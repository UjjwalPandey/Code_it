Problem:
	https://www.interviewbit.com/courses/programming/topics/linked-lists/problems/partitionlist/?ref=dash-reco

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.


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
 * @input B : Integer
 * 
 * @Output head pointer of list.
 */
int listCount(listnode* A){
    int a=0;
    
    while(A!=NULL){
        a++;
        A = A->next;
    }
    return a;
}
listnode* partition(listnode* A, int B) {
    int d = listCount(A);
    if(d==1){
        return A;
    }
    int i=0;
    listnode *end = A, *temp= A;
    while(end->next != NULL){
        end = end->next;
    }
    listnode *prev = A;
    while(i<d && A!=NULL){
        if(temp->val >= B){
            /*if(temp==end){
                break;
            }*/
           
            if(prev == temp && temp->val >= B){
               
                    listnode *create = listnode_new(temp->val);
                    end->next = create;
                    end = create;
                    prev = temp->next;
                    free(temp);
                    A = temp = prev;    
               
                
            }else{
                listnode *create = listnode_new(temp->val);
                end->next = create;
                end = create;
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        }else{
            if(temp!=prev){
                prev = prev->next;
            }
            temp = temp->next;
        }
        i++;
    }
    return A;
}
