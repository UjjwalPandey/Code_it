/* 
Problem:

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 
                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3. 

*/

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
 * 
 * @Output head pointer of list.
 */

listnode* find_start(listnode *slow_p, listnode *A){
    listnode *p1 = slow_p;
    listnode *p2 = slow_p;
    int k =1,i;
	//Get the size k of the loop
    while(p1->next != p2){
        k++;
        p1 = p1->next;
    }
    p1 = A;
    p2 = A;
	//start from beginning and move first pointer k units.
    for(i=0; i<k; i++){
        p1 = p1->next;
    }
	//now move bth pointers simultaneously and  a time will come when both will meet.
    while(p1!= p2){
        p1= p1->next;
        p2 = p2->next;
    }
    return p1;
}

listnode* detectCycle(listnode* A) {
    
	listnode *slow_p = A, *fast_p = A;
 //Take 2 pointers. Move one fast (2 steps) and another one slow.
	  while(slow_p && fast_p && fast_p->next ){
		slow_p = slow_p->next;
		fast_p  = fast_p->next->next;
		//Check for loop. If loop check for common point.
		if (slow_p == fast_p)
		{
		   return find_start(slow_p, A);
		}
	  }
	  return NULL;
}
