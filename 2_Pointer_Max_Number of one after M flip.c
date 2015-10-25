/*
Problem:
	
You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Soultion:

*/
/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* maxone(int* A, int n1, int B, int *len1) {
        int l=0, r = 0;
        int nZero = 0, width = -1, start = 0, end = 0;
        while(r < n1){
            if(nZero <= B)
                if(A[r] == 0){
                    nZero += 1;
                }
                r += 1;
        }
    
    
            if(nZero > B){
                if(A[l] == 0){
                    nZero -= 1;
                }
                l += 1;
            }
    
            if(r - l + 1 > width){
                width = r - l + 1;
                start = l;
                end = r;
            }
            *len1 = end-start;
        int* res = (int*) malloc(sizeof(int)* (*len1));
        int i;
        for(i=start; i< end; i++){
            res[i-start] = i;
        }
        return res;

}
