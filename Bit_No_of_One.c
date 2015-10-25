/*Problem:
	https://www.interviewbit.com/courses/programming/topics/bit-manipulation/problems/num1bits/?ref=dash-reco
Write a function that takes an unsigned integer and returns the number of 1 bits it has.

Example:

The 32-bit integer 11 has binary representation

00000000000000000000000000001011
so the function should return 3.



Solution:
*/
/**
 * @input A : Integer
 * 
 * @Output Integer
 */
int numSetBits(unsigned int A) {
    int count =0,c,k, n=A;
  for (c = 31; c >= 0; c--)
  {
    k = n >> c;
 
    if (k & 1)
      count++;
  }
    return count;
}
