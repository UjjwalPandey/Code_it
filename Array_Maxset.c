/*Problem:
https://www.interviewbit.com/courses/programming/topics/arrays/problems/maxset/
Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index

SOLUTION:
*/
/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @Output Integer array. You need to malloc memory, and fill the length in length_of_array
 */
int* maxset(int* A, int n1, int *length_of_array) {
    *length_of_array = n1;
	//Create a temporary Array of same size
    int * ret = (int *) malloc(sizeof(int) * *length_of_array);
     
    long long sum = 0, maxSum = 0, count = 0, maxCount = 0, i = -1, startIdx = 0;
      
    while(i < n1)
    {
        i++;
        startIdx = i;
        sum = 0;
        count = 0;
		//Starting from a point it iterates till it find positive number.
        while(i < n1 && A[i] >= 0)
        {
            sum += (long long)A[i++];
            count++;
        }
		//If Total sum is greater or if sum is equal and number of elements is greater then change the maxCount value and maxSum value.
        if (sum > maxSum || (sum == maxSum && count > maxCount))
        {
            maxSum = sum;
            maxCount = count;
			//Although we copy it to every element of Array. But later we return maxCount as length of Array.
            memcpy(ret, A + startIdx, sizeof(int) * maxCount);
        }
        
    }
     
     *length_of_array = maxCount;
      return ret;
     
}
