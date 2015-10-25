/*PROBLEM:
	https://www.interviewbit.com/courses/programming/topics/math/problems/arrange/
Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.

Example:

Input : [1, 0]
Return : [0, 1]
 Lets say N = size of the array. Then, following holds true :
* All elements in the array are in the range [0, N-1]
* N * N does not overflow for a signed integer 

SOLUTION:
*/
	First Change each element to number+(A[A[i]]%n)%n and after this divide each number by n.
	
	void arrange(int* A, int n1) {
    int i,x;
    for(i=0; i< n1; i++){
        A[i] += (A[A[i]] % n1)*n1;
    }
    for(i=0; i< n1; i++){
        A[i] /= n1;
    }
    
}
