/*
Problem:
Given an array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example :

Input : [1 2 2 3 1]
Output : 3

Soltuion: */

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int singleNumber(const int* A, int n1) {
      int i,x=0;
 
   
 
    // Let us take the example of {3, 3, 2, 3} to understand this
    for( i=0; i< n1; i++ )
    {
        x = x^A[i];
    }
 
    return x;
}
