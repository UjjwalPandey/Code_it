/*Problem:
	https://www.interviewbit.com/courses/programming/topics/linked-lists/problems/intersectlist/
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:


A:          a1 ? a2
                   ?
                     c1 ? c2 ? c3
                   ?
B:     b1 ? b2 ? b3


Solution:
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
 * @input B : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
 
listnode* _getIntesectionNode(int d, listnode* head1, listnode* head2)
{
  int i;
  listnode* current1 = head1;
  listnode* current2 = head2;
 
  for(i = 0; i < d; i++)
  {
    if(current1 == NULL)
    {  return NULL; }
    current1 = current1->next;
  }
 
  while(current1 !=  NULL && current2 != NULL)
  {
    if(current1 == current2)
      return current1;
    current1= current1->next;
    current2= current2->next;
  }
 
  return NULL;
}
 
/* Takes head pointer of the linked list and
   returns the count of nodes in the list */
int getCount(listnode* head)
{
  listnode* current = head;
  int count = 0;
 
  while (current != NULL)
  {
    count++;
    current = current->next;
  }
 
  return count;
}
listnode* getIntersectionNode(listnode* A, listnode* B) {
    int c1 = getCount(A);
  int c2 = getCount(B);
  int d;
 
  if(c1 > c2)
  {
    d = c1 - c2;
    return _getIntesectionNode(d, A, B);
  }
  else
  {
    d = c2 - c1;
    return _getIntesectionNode(d, B, A);
  }
    
}
