/*Problem:
https://www.interviewbit.com/courses/programming/topics/arrays/problems/wave/

Given an array of integers, sort the array into a wave like array and return it, 
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

Example

Given [1, 2, 3, 4]

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]
 NOTE : If there are multiple answers possible, return the one thats lexicographically smallest. 
 
 Solution:
 */
 /**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
 int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int* wave(int* A, int n1, int *len1) {
	//Sort the Array first.
    qsort(A, n1, sizeof(int),cmpfunc);
     
    int i,temp;
    //Interchange every next 2 number.
    for(i=0; i<n1-1; ){
        temp = A[i];
        A[i] = A[i+1];
        A[i+1] = temp;
        i = i+2;
    }
    for(i=0; i<n1; i++){
         printf("%d ",A[i]);
     }
    return NULL;
}
